package io.innofang.aop;

import org.springframework.aop.ThrowsAdvice;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public class HijackThrowExceptionMethod implements ThrowsAdvice {

    public void afterThrowing(IllegalArgumentException e) throws Throwable {
        System.out.println("HijackThrowException : Throw exception hijacked!");
    }
}
