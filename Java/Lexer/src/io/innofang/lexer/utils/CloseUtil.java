package io.innofang.lexer.utils;

import java.io.Closeable;
import java.io.IOException;

/**
 * Created with IntelliJ IDEA
 * Created By Inno Fang
 * Date: 2018/5/21
 * Time: 21:10
 */
public class CloseUtil {
    public static void close(Closeable closeable) {
        if (closeable != null) {
            try {
                closeable.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
