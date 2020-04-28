package io.github.innofang.step3;


import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

import java.io.IOException;

/**
 * 输入： output/step1/part-r-00000
 * 输出： output/step3
 */
public class MR3 {

    private static Path inputPath = new Path("output/step1/part-r-00000");
    private static Path outputPath = new Path("output/step3");

    public static boolean run() throws IOException, ClassNotFoundException, InterruptedException {
        // 创建　job 配置类
        Configuration conf = new Configuration();
        FileSystem fs = FileSystem.get(conf);
        if (fs.exists(outputPath)) {
            fs.delete(outputPath, true);
            System.out.println(outputPath.toString() + " was existed and have been recreated.");
        }

        // 创建　job 实例
        Job job = Job.getInstance(conf, "Matrix Transposition");
        // 设置　job 主类
        job.setJarByClass(MR3.class);

        // 设置　job 的　Mapper 和　Reducer4
        job.setMapperClass(Mapper3.class);
        job.setReducerClass(Reducer3.class);

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
            boolean complete = MR3.run();
            if (complete) {
                System.out.println("MR3 run successfully.");
            } else {
                System.out.println("MR3 run failed.");
            }
        } catch (IOException | InterruptedException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}