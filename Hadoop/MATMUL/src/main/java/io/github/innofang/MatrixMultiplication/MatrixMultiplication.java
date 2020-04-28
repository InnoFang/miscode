package io.github.innofang.MatrixMultiplication;


import io.github.innofang.MatrixTransposition.MatrixTranspositionMapper;
import io.github.innofang.MatrixTransposition.MatrixTranspositionReducer;
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
 * 输入： input/matrix2.txt
 * 输出： output
 * 缓存输入: input/matrix2T.txt
 */
public class MatrixMultiplication {

    private static int run(Path inputPath, Path outputPath, Path cachePath) throws IOException, ClassNotFoundException, InterruptedException, URISyntaxException {

        // 创建　job 配置类
        Configuration conf = new Configuration();
        FileSystem fs = FileSystem.get(conf);
        if (fs.exists(outputPath)) {
            fs.delete(outputPath, true);
            System.out.println("Output file existed, but it has been deleted.");
        }

        // 创建　job 实例
        Job job = Job.getInstance(conf, "Matrix Multiplication");
        // 设置　job 主类
        job.setJarByClass(MatrixMultiplication.class);

        // 设置分布式缓存文件 (cachePath#别名, matrix2即别名, 读入时便于辨别)
        job.addCacheArchive(new URI(cachePath + "#matrix2T"));

        // 设置　job 的　Mapper 和　Reducer
        job.setMapperClass(MatrixMultiplicationMapper.class);
        job.setReducerClass(MatrixMultiplicationReducer.class);

        // 设置　Reducer 输出类型
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(Text.class);

        // 设置输入和输出路径
        FileInputFormat.addInputPath(job, inputPath);
        FileOutputFormat.setOutputPath(job, outputPath);

        return job.waitForCompletion(true) ? 0 : 1;
    }

    public static void main(String[] args) {
        if (args.length < 3) {
            System.out.println("Usage: MatrixMultiplication <input path> <output path> <cache path>");
            System.exit(-1);
        }

        try {
            int result = MatrixMultiplication.run(new Path(args[0]), new Path(args[1]), new Path(args[2]));
            if (result == 1) {
                System.out.println("MatrixMultiplication run failed.");
            } else {
                System.out.println("MatrixMultiplication run successfully.");
            }
        } catch (IOException | InterruptedException | ClassNotFoundException | URISyntaxException e) {
            e.printStackTrace();
        }
    }
}
