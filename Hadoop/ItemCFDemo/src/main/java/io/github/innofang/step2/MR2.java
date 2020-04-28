package io.github.innofang.step2;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;


/**
 * 输入： output/step1/part-r-00000
 * 输出： output/step2/
 * 缓存输入: output/step1/part-r-00000
 */
public class MR2 {

    private static Path inputPath = new Path("output/step1/part-r-00000");
    private static Path outputPath = new Path("output/step2/");
    private static Path cachePath = new Path("output/step1/part-r-00000");


    public static boolean run() throws IOException, ClassNotFoundException, InterruptedException, URISyntaxException {
        // 创建　job 配置类
        Configuration conf = new Configuration();
        FileSystem fs = FileSystem.get(conf);
        if (fs.exists(outputPath)) {
            fs.delete(outputPath, true);
            System.out.println(outputPath.toString() + " was existed and have been recreated.");
        }

        // 创建　job 实例
        Job job = Job.getInstance(conf, "Score Matrix Multiplication");
        // 设置　job 主类
        job.setJarByClass(MR2.class);

        // 设置分布式缓存文件 (cachePath#别名, itemUserScore1即别名, 读入时便于辨别)
        job.addCacheArchive(new URI(cachePath + "#itemUserScore1"));

        // 设置　job 的　Mapper 和　Reducer4
        job.setMapperClass(Mapper2.class);
        job.setReducerClass(Reducer2.class);

        // 设置　Reducer4 输出类型
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(Text.class);

        // 设置输入和输出路径
        FileInputFormat.addInputPath(job, inputPath);
        FileOutputFormat.setOutputPath(job, outputPath);

        return job.waitForCompletion(true);
    }

    public static void main(String[] args) {
        try {
            boolean complete = MR2.run();
            if (complete) {
                System.out.println("MR2 run successfully.");
            } else {
                System.out.println("MR2 run failed.");
            }
        } catch (IOException | InterruptedException | ClassNotFoundException | URISyntaxException e) {
            e.printStackTrace();
        }
    }
}