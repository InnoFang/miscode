package io.innofang.aop;

import org.springframework.aop.AfterReturningAdvice;

import java.lang.reflect.Method;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public class HijackAfterMethod implements AfterReturningAdvice {
    /**
     * method 运行后，直到返回结果后，才运行下边的代码，如果没有返回结果，将不运行切入的代码
     * @param o
     * @param method
     * @param objects
     * @param o1
     * @throws Throwable
     */
    public void afterReturning(Object o, Method method, Object[] objects, Object o1) throws Throwable {
        System.out.println("HijackAfterMethod : After method hijacked!");
    }
}
