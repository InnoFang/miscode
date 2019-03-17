package io.github.innofang.hadoop.mapreduce;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Partitioner;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

import java.io.IOException;

public class PartitionerApp {

    /**
     * Map：读取输入的文件
     */
    public static class MyMapper extends Mapper<LongWritable, Text, Text, LongWritable> {


        @Override
        protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
            // 接收到每一行数据
            String line = value.toString();
            // 按照指定分隔符进行拆分
            String[] words = line.split(" ");

            context.write(new Text(words[0]), new LongWritable(Long.parseLong(words[1])));
        }
    }

    /**
     * Reducer：归并操作
     */
    public static class MyReducer extends Reducer<Text, LongWritable, Text, LongWritable> {
        @Override
        protected void reduce(Text key, Iterable<LongWritable> values, Context context) throws IOException, InterruptedException {

            long sum = 0;
            for (LongWritable value: values) {
                // 求 key 出现次数的总和
                sum += value.get();
            }
            context.write(key, new LongWritable(sum));
        }

    }

    public static class MyPartitioner extends Partitioner<Text, LongWritable> {

        @Override
        public int getPartition(Text key, LongWritable longWritable, int i) {
            if (key.toString().equals("xiaomi")) {
                return 0;
            }
            if (key.toString().equals("huawei")) {
                return 1;
            }
            if (key.toString().equals("iphone7")) {
                return 2;
            }

            return 3;
        }
    }

    /**
     * 定义 Driver：封装了 MapReduce 作业的所有信息
     */
    public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
        // 创建 Configuration
        Configuration configuration = new Configuration();

        if (args.length < 2) {
            System.out.println("Please specify the complete command.");
            System.out.println("    hadoop jar <jar file> <main class> <input file> <output file>.");
            System.exit(0);
        }

        // 准备清理已存在的输出目录
        Path outputPath = new Path(args[1]);
        FileSystem fileSystem = FileSystem.get(configuration);
        if (fileSystem.exists(outputPath)) {
            fileSystem.delete(outputPath, true);
            System.out.println("Output file exists, but it has deleted.");
        }

        // 创建 Job
        Job job = Job.getInstance(configuration, "wordcount");

        // 设置 job 处理类
        job.setJarByClass(PartitionerApp.class);

        // 设置作业处理的输入路径
        FileInputFormat.setInputPaths(job, new Path(args[0]));

        // 设置 map 相关参数
        job.setMapperClass(MyMapper.class);
        job.setMapOutputKeyClass(Text.class);
        job.setMapOutputValueClass(LongWritable.class);

        // 设置 reduce 相关参数
        job.setReducerClass(MyReducer.class);
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(LongWritable.class);

        // 设置 Job 的 Partition
        job.setPartitionerClass(MyPartitioner.class);
        // 设置 4 个 reducer, 每个分区一个
        job.setNumReduceTasks(4);

        // 设置作业处理的输出路径
        FileOutputFormat.setOutputPath(job, new Path(args[1]));

        System.exit(job.waitForCompletion(true) ? 0 : 1);

        // 编译： mvn clean package -DskipTest
        // 上传： scp target/hadoop-train-1.0.jar innofang@localhost:~/lib
                // jar 在 target 下面; lib 需要提前创建好
        // 运行： hadoop jar /home/innofang/lib/hadoop-train-1.0.jar io.github.innofang.hadoop.mapreduce.WordCountApp hdfs://localhost:9000/hello.txt hdfs://localhost:9000/output/wc

        /*
            在 ResourceManager 中，输出文件是不能事先存在的
            1）先手工通过 shell 的方式将输出文件夹删除
                hadoop fs -rm -r /output/wc
            2）在代码中完成自动删除功能（推荐）
         */

        /* MapReduce 编程之 Combiner
        Combiner 相当于本地的 Reducer，减少 Map Tasks 输出的数据量及数据网络传输量
        但要注意使用场景：在求和、词频是没问题，但如果是诸如求平均数等则不适合使用 Combiner
         */

        /* MapReduce 编程之 Partitioner
            Partitioner 决定 MapTask 输出的数据交由哪个 ReducerTask 处理
            默认实现：分发的 Key 的 hash 值对 Reduce Task 个数取模

            hadoop jar /home/innofang/lib/hadoop-train-1.0.jar io.github.innofang.hadoop.mapreduce.PartitionerApp hdfs://localhost:9000/partitioner hdfs://localhost:9000/output/partitioner
         */
    }
}