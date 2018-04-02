package io.innofang.aop;

import org.springframework.aop.MethodBeforeAdvice;

import java.lang.reflect.Method;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public class HijackMethodBeforeAdvice implements MethodBeforeAdvice {

    /**
     * method 运行前，将运行下面的代码
     * @param method
     * @param objects
     * @param o
     * @throws Throwable
     */
    public void before(Method method, Object[] objects, Object o) throws Throwable {
        System.out.println("HijackBeforeMethod : Before method hijacked!" );
    }
}
