package io.github.innofang.step2;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

public class Mapper2 extends Mapper<LongWritable, Text, Text, Text> {

    private List<String> cacheList = new ArrayList<>();
    private DecimalFormat df = new DecimalFormat("0.00");
    private Text outKey = new Text();
    private Text outVal = new Text();
    @Override
    protected void setup(Context context) throws IOException, InterruptedException {
        // itemUserScore1 是缓存文件别名
        FileReader fr = new FileReader("itemUserScore1");
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
        // 行
        String itemId1 = rowAndLine[0];
        // 列 与 值
        String[] userIdAndScoreArray1 = rowAndLine[1].split(",");

        // 计算用户，物品的评分矩阵的余弦相似度
        // 分母
        double denominator1 = 0;
        for (String userIdAndScore1 : userIdAndScoreArray1) {
           double score1 = Double.valueOf(userIdAndScore1.split("_")[1]);
           denominator1 += score1 * score1;
        }
        denominator1 = Math.sqrt(denominator1);

        for (String cacheLine : cacheList) {
            String[] rowAndLine2 = cacheLine.split("\\s+");
            String itemId2 = rowAndLine2[0];
            String[] userIdAndScoreArray2 = rowAndLine2[1].split(",");

            double numerator = 0;
            double denominator2 = 0;
            for (String userIdAndScore2 : userIdAndScoreArray2) {
                String[] uAs = userIdAndScore2.split("_");
                String userId2 = uAs[0];
                Double score2 = Double.valueOf(uAs[1]);

                denominator2 += score2 * score2;
                for (String userIdAndScore1 : userIdAndScoreArray1) {
                    if (userIdAndScore1.startsWith(userId2 + "_")) {
                        double score1 = Double.valueOf(userIdAndScore1.split("_")[1]);
                        numerator += score1 * score2;
                    }
                }
            }

            denominator2 = Math.sqrt(denominator2);

            double cos = numerator / ( denominator1 * denominator2 );
            if (Math.abs(cos) < 0.001) {
                continue;
            }

            outKey.set(itemId1);
            outVal.set(itemId2 + "_" + df.format(cos));
            context.write(outKey, outVal);
        }
    }
}
