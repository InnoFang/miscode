package io.github.innofang.MatrixMultiplication;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MatrixMultiplicationMapper extends Mapper<LongWritable, Text, Text, Text> {

    private Text outKey = new Text();
    private Text outVal = new Text();
    private List<String> cacheList = new ArrayList<>();

    @Override
    protected void setup(Context context) throws IOException, InterruptedException {
        super.setup(context);
        // 通过输入流将全局缓存中的右侧矩阵读入到　List<String> 中 (matrix2即别名, 在设置缓存路径 Uri 时指定)
        FileReader fr = new FileReader("matrix2T");
        BufferedReader br = new BufferedReader(fr);

        // 每一行的格式为:　行号  列号_值,列号_值,...
        String line;
        while ((line = br.readLine()) != null) {
            cacheList.add(line);
        }
    }

    @Override
    protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
        String[] rowAndLine1 = value.toString().split("\\s+");

        // 左侧矩阵行号
        String row1 = rowAndLine1[0];
        // 左侧矩阵的行 (列名_值 数组)
        String[] colValArray1 = rowAndLine1[1].split(",");

        for (String cacheLine : cacheList) {
            String[] rowAndLine2 = cacheLine.split("\\s+");
            // 右侧矩阵行号
            String row2 = rowAndLine2[0];
            // 右侧矩阵的行 (列名_值 数组)
            String[] colValArray2 = rowAndLine2[1].split(",");

            // 矩阵两行相乘得到的结果
            int result = 0;

            // 遍历左边矩阵的第一行的每一列
            for (String colAndVal1 : colValArray1) {
                String[] cAv1 = colAndVal1.split("_");
                String column1 = cAv1[0];
                String value1 = cAv1[1];

                // 遍历右边矩阵每一行的每一列
                for (String colAndVal2 : colValArray2) {
                    if (colAndVal2.startsWith(column1 + "_")) {
                        String[] cAv2 = colAndVal2.split("_");
                        String column2 = cAv2[0];
                        String value2 = cAv2[1];

                        result += Integer.valueOf(value1) * Integer.valueOf(value2);
                    }
                }
            }
            // result 是结果矩阵中的某元素，坐标为　行: row1 列:row2 (右边矩阵已转置)
            outKey.set(row1);
            outVal.set(row2 + "_" + result);
            context.write(outKey, outVal);
        }
    }
}
