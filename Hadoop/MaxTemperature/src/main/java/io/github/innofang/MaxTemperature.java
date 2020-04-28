package io.github.innofang;


import org.apache.commons.math3.analysis.function.Max;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

import java.io.IOException;

/**
 * 输入：/input/ncdc/1901.gz   /input/ncdc/1902.gz
 * 输出：/output
 */

public class MaxTemperature {

    private static int run(Path outputPath, Path... inputPaths) throws IOException, ClassNotFoundException, InterruptedException {

        // 创建　job 配置类
        Configuration conf = new Configuration();
        FileSystem fs = FileSystem.get(conf);
        if (fs.exists(outputPath)) {
            fs.delete(outputPath, true);
            System.out.println("Output file existed, but it has been deleted.");
        }

        // 创建　job 实例
        Job job = Job.getInstance(conf, "Max Temperature");
        // 设置　job 主类
        job.setJarByClass(MaxTemperature.class);

        // 设置　job 的　Mapper 和　Reducer
        job.setMapperClass(MaxTemperatureMapper.class);
        job.setCombinerClass(MaxTemperatureReducer.class);
        job.setReducerClass(MaxTemperatureReducer.class);

        // 设置　Reducer 输出类型
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(IntWritable.class);

        // 设置输入和输出路径
        FileInputFormat.setInputPaths(job, inputPaths);
        FileOutputFormat.setOutputPath(job, outputPath);

        return job.waitForCompletion(true) ? 0 : 1;
    }

    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Usage: maxTemperature <output path> <input path1> <input path2> ...");
            System.exit(-1);
        }

        Path outputPath = new Path(args[0]);
        Path[] inputPaths = new Path[args.length - 1];
        for (int i = 1; i < args.length; i++) {
            inputPaths[i - 1] = new Path(args[i]);
        }


        try {
            int result = MaxTemperature.run(outputPath, inputPaths);
            if (result == 1) {
                System.out.println("MaxTemperature run failed.");
            } else {
                System.out.println("MaxTemperature run successfully.");
            }
        } catch (IOException | InterruptedException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
