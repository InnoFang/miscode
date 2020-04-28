package io.github.innofang.step1;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

import java.io.IOException;
import java.net.URISyntaxException;


/**
 * 输入： input/step1/actionList.txt
 * 输出： output/step1/
 */
public class MR1 {

    private static Path inputPath = new Path("input/step1/actionList.txt");
    private static Path outputPath = new Path("output/step1/");

    public static boolean run() throws IOException, ClassNotFoundException, InterruptedException, URISyntaxException {
        // 创建　job 配置类
        Configuration conf = new Configuration();
        FileSystem fs = FileSystem.get(conf);
        if (fs.exists(outputPath)) {
            fs.delete(outputPath, true);
            System.out.println(outputPath.toString() + " was existed and have been recreated.");
        }

        // 创建　job 实例
        Job job = Job.getInstance(conf, "Matrix Multiplication");
        // 设置　job 主类
        job.setJarByClass(MR1.class);

        // 设置　job 的　Mapper 和　Reducer4
        job.setMapperClass(Mapper1.class);
        job.setReducerClass(Reducer1.class);

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
            boolean complete = MR1.run();
            if (complete) {
                System.out.println("MR1 run successfully.");
            } else {
                System.out.println("MR1 run failed.");
            }
        } catch (IOException | InterruptedException | ClassNotFoundException | URISyntaxException e) {
            e.printStackTrace();
        }
    }
}
