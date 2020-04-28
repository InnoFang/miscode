package io.github.innofang.step1;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;
import java.util.HashMap;
import java.util.StringJoiner;

public class Reducer1 extends Reducer<Text, Text, Text, Text> {
    private Text outVal = new Text();
    @Override
    protected void reduce(Text key, Iterable<Text> values, Context context) throws IOException, InterruptedException {
        // 统计并汇总用户对商品的行为分数
        HashMap<String, Integer> store = new HashMap<>();
        for (Text value : values) {
            String[] userAndScore = value.toString().split("_");
            String userId = userAndScore[0];
            Integer score = Integer.valueOf(userAndScore[1]);
            score += store.getOrDefault(userId, 0);
            store.put(userId, score);
        }

        // 重新连接成 用户_分数,用户_分数,... 的形式
        StringJoiner joiner = new StringJoiner(",");
        store.forEach((k, v) -> joiner.add(k + "_" + v));
        outVal.set(joiner.toString());

        context.write(key, outVal);
    }
}
