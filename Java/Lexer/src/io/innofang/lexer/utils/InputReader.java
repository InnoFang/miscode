package io.innofang.lexer.utils;

import java.io.*;
import java.util.StringTokenizer;

/**
 * Created with IntelliJ IDEA
 * Created By Inno Fang
 * Date: 2018/5/21
 * Time: 15:14
 */
public class InputReader extends BufferedReader {

    private StringTokenizer st;

    public InputReader(InputStream in) {
        super(new InputStreamReader(in));
        eat("");
    }

    void eat(String s) {
        st = new StringTokenizer(s);
    }

    public String nextLine() {
        try {
            return readLine();
        } catch (IOException e) {
            throw new IOError(e);
        }
    }

    public boolean hasNext() {
        while (!st.hasMoreTokens()) {
            String s = nextLine();
            if (null == s || s.isEmpty()) return false;
            eat(s);
        }
        return true;
    }

    public String next(){
        hasNext();
        return st.nextToken();
    }
}
