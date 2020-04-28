package io.github.innofang.step1;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

/**
 * Input:
 * key  value(userId,itemId,score)
 * 1    A,1,1
 * 2    C,3,5
 * 3    B,2,3
 *
 * Output:
 * (itemId) (userId_score)
 * key      value
 * 1        A_1
 * 3        C_5
 * 2        B_3
 */

public class Mapper1 extends Mapper<LongWritable, Text, Text, Text> {

    private Text outkey = new Text();
    private Text outVal = new Text();

    @Override
    protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
        String[] line = value.toString().split(",");
        String userId = line[0];
        String itemId = line[1];
        String score = line[2];
        outkey.set(itemId);
        outVal.set(userId + "_" + score);
        context.write(outkey, outVal);
    }
}
