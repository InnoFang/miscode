package io.innofang.lexer.handler;

import io.innofang.lexer.exception.InvalidTokenException;

/**
 * Created with IntelliJ IDEA
 * Created By Inno Fang
 * Date: 2018/5/22
 * Time: 20:08
 */
public class ExceptionHandler implements Thread.UncaughtExceptionHandler {
    @Override
    public void uncaughtException(Thread t, Throwable e) {
        if (e instanceof InvalidTokenException) {
            System.out.println(e.getMessage());
        }
    }
}
