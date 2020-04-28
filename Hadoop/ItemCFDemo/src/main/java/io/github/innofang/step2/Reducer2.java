package io.github.innofang.step2;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;
import java.util.StringJoiner;

public class Reducer2 extends Reducer<Text, Text, Text, Text> {
    private Text outVal = new Text();
    @Override
    protected void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
        StringJoiner joiner = new StringJoiner(",");
        values.forEach(text -> joiner.add(text.toString()));
        outVal.set(joiner.toString());
        context.write(key, outVal);
    }
}
