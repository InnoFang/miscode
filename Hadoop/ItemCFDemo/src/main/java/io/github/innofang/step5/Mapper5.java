package io.github.innofang.step5;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Mapper5 extends Mapper<LongWritable, Text, Text, Text> {

    private List<String> cacheList = new ArrayList<>();
    private Text outKey = new Text();
    private Text outVal = new Text();

    @Override
    protected void setup(Context context) throws IOException, InterruptedException {
        FileReader fr = new FileReader("itemUserScore3");
        BufferedReader br = new BufferedReader(fr);

        String line;
        while ((line = br.readLine()) != null) {
            cacheList.add(line);
        }

        br.close();
        fr.close();
    }

    @Override
    protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
        String[] rowAndLine = value.toString().split("\\s+");
        String itemId1 = rowAndLine[0];
        String[] userIdAndScoreArray1 = rowAndLine[1].split(",");

        for (String cacheLine : cacheList) {
            String[] rowAndLine2 = cacheLine.split("\\s+");
            String itemId2 = rowAndLine2[0];
            String[] userIdAndScoreArray2 = rowAndLine2[1].split(",");

            if (itemId1.equals(itemId2)) {
                for (String userIdAndScore1 : userIdAndScoreArray1) {
                    String[] uAs1 = userIdAndScore1.split("_");
                    String userId1 = uAs1[0];
                    String score1 = uAs1[1];

                    boolean exist = false;
                    for (String userIdAndScore2 : userIdAndScoreArray2) {
                        String[] uAs2 = userIdAndScore2.split("_");
                        String userId2 = uAs2[0];

                        if (userId1.equals(userId2)) {
                            exist = true;
                        }
                    }
                    if (!exist) {
                        outKey.set(userId1);
                        outVal.set(itemId1 + "_" + score1);
                        context.write(outKey, outVal);
                    }
                }
            }
        }
    }
}
