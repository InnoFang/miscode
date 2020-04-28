package io.github.innofang.MatrixMultiplication;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;
import java.util.StringJoiner;

public class MatrixMultiplicationReducer extends Reducer<Text, Text, Text, Text> {

    private Text outVal = new Text();
    /**
     * @param key   列号
     * @param values    {行号_值, 行号_值, 行号_值, ...}
     */
    @Override
    protected void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
        // 把 values 用 ',' 拼接成一行
        StringJoiner line = new StringJoiner(",");
        values.forEach(text -> line.add(text.toString()));
        outVal.set(line.toString());
        context.write(key, outVal);
    }
}
