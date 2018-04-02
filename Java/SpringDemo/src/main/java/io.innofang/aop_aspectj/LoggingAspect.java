package io.innofang.aop_aspectj;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;

/**
 * Created by Inno Fang on 2018/4/2.
 */
@Aspect
public class LoggingAspect {

//    @Before("execution(public * io.innofang.aop_aspectj.Customer.addCustomer())")
    @Before("io.innofang.aop_aspectj.PointcutsDefinition.customerLog()")
    public void logBefore(JoinPoint joinPoint){
        System.out.println("logBefore() is running ...");
        System.out.println("hijacked:"+joinPoint.getSignature().getName());
        System.out.println("**********");
    }

//    @After("execution(public * io.innofang.aop_aspectj.Customer.deleteCustomer(..))")
    @After("io.innofang.aop_aspectj.PointcutsDefinition.customerLog()")
    public void logAfter(JoinPoint joinPoint){
        System.out.println("logAfter() is running ...");
        System.out.println("hijacked:"+joinPoint.getSignature().getName());
        System.out.println("**********");
    }

}
