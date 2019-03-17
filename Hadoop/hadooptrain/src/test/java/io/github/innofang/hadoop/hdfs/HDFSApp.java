package io.github.innofang.hadoop.hdfs;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.*;
import org.apache.hadoop.io.IOUtils;
import org.apache.hadoop.util.Progressable;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.net.URI;

/**
 * Hadoop HDFS Java Api 操作
 */


public class HDFSApp {

    public static final String HDFS_PATH = "hdfs://localhost:9000";

     FileSystem fileSystem;
     Configuration configuration;

     @Before
    public void setUp() throws Exception {
        System.out.println("HDFSApp setUp is called.");
        configuration = new Configuration();
        fileSystem = FileSystem.get(new URI(HDFS_PATH), configuration, "innofang");
    }

    @After
    public void tearDown() throws Exception {
        fileSystem = null;
        configuration = null;
        System.out.println("HDFSAPP tearDown is called.");
    }

    /**
     * 创建 HDFS 文件夹
     * @throws Exception
     */
    @Test
    public void mkdir() throws Exception {
        fileSystem.mkdirs(new Path("/hdfsapi/test"));
    }


    /**
     * 创建文件
     * @throws Exception
     */
    @Test
    public void create() throws Exception {
        FSDataOutputStream output =
              fileSystem.create(new Path("/hdfsapi/test/a.txt"));
        byte[] content = "Hello Hadoop".getBytes();
        output.write(content);
        output.flush();
        output.close();
    }

    /**
     * 查看 HDFS 文件的内容
     * @throws Exception
     */
    @Test
    public void cat() throws Exception {
        FSDataInputStream in =
             fileSystem.open(new Path("/hdfsapi/test/a.txt"));
        IOUtils.copyBytes(in, System.out, 1024);
        in.close();
    }

    /**
     * 重命名
     * @throws Exception
     */
    @Test
    public void rename() throws Exception {
        Path oldPath = new Path("/hdfsapi/test/a.txt");
        Path newPath = new Path("/hdfsapi/test/b.txt");
        fileSystem.rename(oldPath, newPath);
    }

    /**
     * 上传文件到 HDFS
     * @throws Exception
     */
    @Test
    public void copyFromLocalFile() throws Exception {
        Path localPath = new Path("/home/innofang/data/hello.txt");
        Path hdfsPath = new Path("/hdfsapi/test/");
        fileSystem.copyFromLocalFile(localPath, hdfsPath);
    }

    /**
     * 上传文件到 HDFS （带进度条）
     * @throws Exception
     */
    @Test
    public void copyFromLocalFileWithProgress() throws Exception {
        InputStream in = new BufferedInputStream(
                new FileInputStream(
                        new File("/home/innofang/Downloads/jdk-8u192-linux-x64.tar.gz")));

        FSDataOutputStream output = fileSystem.create(new Path("/hdfsapi/test/jdk.tar.gz"),
             new Progressable() {
                 public void progress() {
                     System.out.println(".");
                 }
             });

        IOUtils.copyBytes(in, output, 4096);
    }

    /**
     * 下载 HDFS 文件到本地
     * @throws Exception
     */
    @Test
    public void copyToLocalFile() throws Exception {
        Path localPath = new Path("/home/innofang/data/test.txt");
        Path hdfsPath  = new Path("/hdfsapi/test/a.txt");
        fileSystem.copyToLocalFile(hdfsPath, localPath);
    }

    /**
     * 查看某个目录下的所有文件
     * @throws Exception
     *
     * 使用 HDFS shell 的方式 put 的文件，采用 hdfs-site.xml 中设置的副本系数
     * 使用 Java Api 上传的文件，因为在本地并没有手工设置副本系数，所以采用的是 Hadoop 默认的副本系数
     */
    @Test
    public void listFiles() throws Exception {
        FileStatus[] fileStatus = fileSystem.listStatus(
             new Path("/hdfsapi/test"));

        for(FileStatus status: fileStatus) {
             String isDir = status.isDirectory() ? "文件夹" : "文件";
             short replication = status.getReplication();
             long len = status.getLen();
             String path = status.getPath().toString();

             System.out.println(isDir + "\t" + replication + "\t" + len + "\t" + path);
        }
    }

    /**
     * 删除文件
     * @throws Exception
     */
    @Test
    public void delete() throws Exception {
        fileSystem.delete(new Path("/hdfsapi/test"), true);
    }
}
