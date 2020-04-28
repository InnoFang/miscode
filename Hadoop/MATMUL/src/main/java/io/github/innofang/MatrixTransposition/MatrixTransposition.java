package io.github.innofang.MatrixTransposition;


import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

import java.io.IOException;


/**
 * 输入： input/matrix2.txt
 * 输出： output
 */
public class MatrixTransposition {

    private static int run(Path inputPath, Path outputPath) throws IOException, ClassNotFoundException, InterruptedException {

        // 创建　job 配置类
        Configuration conf = new Configuration();
        FileSystem fs = FileSystem.get(conf);
        if (fs.exists(outputPath)) {
            fs.delete(outputPath, true);
            System.out.println("Output file existed, but it has been deleted.");
        }

        // 创建　job 实例
        Job job = Job.getInstance(conf, "Matrix Transposition");
        // 设置　job 主类
        job.setJarByClass(MatrixTransposition.class);

        // 设置　job 的　Mapper 和　Reducer
        job.setMapperClass(MatrixTranspositionMapper.class);
        job.setReducerClass(MatrixTranspositionReducer.class);

        // 设置　Reducer 输出类型
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(Text.class);

        // 设置输入和输出路径
        FileInputFormat.addInputPath(job, inputPath);
        FileOutputFormat.setOutputPath(job, outputPath);

        return job.waitForCompletion(true) ? 0 : 1;
    }

    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Usage: MatrixTransposition <input path> <output path>");
            System.exit(-1);
        }

        try {
            int result = MatrixTransposition.run(new Path(args[0]), new Path(args[1]));
            if (result == 1) {
                System.out.println("MatrixTransposition run failed.");
            } else {
                System.out.println("MatrixTransposition run successfully.");
            }
        } catch (IOException | InterruptedException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
