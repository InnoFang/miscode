package io.github.innofang;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

import java.io.IOException;

/**
 * 文本地址：
 * input/ncdc/sample.txt
 *
 * 文本样例
 * 0067011990999991950051507004+68750+023550FM-12+038299999V0203301N00671220001CN9999999N9+00001+99999999999
 *
 * 文本格式
 * 0067
 * 011990   # USAF weather station identifier
 * 99999    # WBAN weather station identifier
 * 19500515 # observation date
 * 0700     # observation time
 * 4
 * +68750   # latitude (degrees x 1000)
 * +023550  # longitude (degrees x 1000)
 * FM-12
 * +0382    # elevation (meters)
 * 99999
 * V020
 * 330      # wind direction (degrees)
 * 1        # quality code
 * N
 * 0067
 * 1
 * 22000    # sky ceiling height (meters)
 * 1        # quality code
 * C
 * N
 * 999999   # visibility distance (meters)
 * 9        # quality code
 * N
 * 9
 * +0000    # air temperature (degrees Celsius x 10)
 * 1        # quality code
 * +9999    # dew point temperature (degrees Celsius x 10)
 * 9        # quality code
 * 99999    # atmospheric pressure (hectopascals x 10)
 * 9        # quality code
 *
 * 该 Mapper 的作用：将文本中对应年份的温度数据提取出来，（键，值）为（年份，温度）
 */

public class MaxTemperatureMapper extends Mapper<LongWritable, Text, Text, IntWritable> {

    // 温度检测缺失值
    private static final int MISSING = 9999;

    @Override
    protected void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
        String line = value.toString();
        String year = line.substring(15, 19);
        int airTemperature;
        if (line.charAt(87) == '+') {
            // 正数不需要 + 号
            airTemperature = Integer.parseInt(line.substring(88, 92));
        } else {
            // 负数需要使用带 - 号
            airTemperature = Integer.parseInt(line.substring(87, 92));
        }
        String quality = line.substring(92, 93);
        // 温度值未缺失，且质量值为 0, 1, 4, 5, 9 其中一个
        if (airTemperature != MISSING && quality.matches("[01459]")) {
            context.write(new Text(year), new IntWritable(airTemperature));
        }
    }
}
