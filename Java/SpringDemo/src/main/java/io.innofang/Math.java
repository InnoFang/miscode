package io.innofang;

/**
 * Created by Inno Fang on 2018/3/29.
 */
public class Math {

    public int factorial(int n ) throws Exception{
        if (n < 0 ) throw new Exception("negative number is illegal.");
        else if (n <= 1) return 1;
        else return n * factorial(n - 1);
    }
}
