package io.innofang.aop;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public class CustomServiceTest {

    @Test
    public void test() {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-aop.xml");
        CustomService cs = (CustomService) context.getBean("custom_service_proxy");
        System.out.println("*************************");
        cs.printName();
        System.out.println("*************************");
        cs.printUrl();
        System.out.println("*************************");
        try {
            cs.printThrowException();
        } catch (Exception e) {
            System.out.println("handle exception.");
        }
    }

}