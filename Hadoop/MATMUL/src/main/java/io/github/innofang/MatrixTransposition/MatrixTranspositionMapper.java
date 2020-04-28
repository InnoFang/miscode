package io.github.innofang.MatrixTransposition;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

public class MatrixTranspositionMapper extends Mapper<LongWritable, Text, Text, Text> {

    private Text outKey = new Text();
    private Text outVal = new Text();

    /**
     * @param key   1   行号
     * @param value 1_0,2_3,3_-1,4_2,5_-3   列号_值
     */
    @Override
    protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {

        String[] rowAndLine = value.toString().split("\\s+");

        // 行号
        String row = rowAndLine[0];
        // 列名_值
        String[] lines = rowAndLine[1].split(",");

        // {"1_0" ,"2_3", "3_-1", "4_2", "5_-3"}
        for (String colAndVal : lines) {
            String[] cAv = colAndVal.split("_");
            outKey.set(cAv[0]);
            outVal.set(row + "_" + cAv[1]);
            context.write(outKey, outVal);
        }
    }
}
