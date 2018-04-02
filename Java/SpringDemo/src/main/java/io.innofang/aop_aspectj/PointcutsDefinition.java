package io.innofang.aop_aspectj;

import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;

/**
 * Created by Inno Fang on 2018/4/2.
 */
@Aspect
public class PointcutsDefinition {

    @Pointcut("execution(* io.innofang.aop_aspectj.Customer.*(..))")
    public void customerLog() {

    }
}
