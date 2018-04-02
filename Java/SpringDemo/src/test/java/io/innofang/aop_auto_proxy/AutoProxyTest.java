package io.innofang.aop_auto_proxy;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public class AutoProxyTest {

    @Test
    public void test() {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-aop-auto-proxy.xml");
        Student s = (Student) context.getBean("student_fang");
        s.gotoWalk();
        System.out.println("---------------------");
        s.stopWalking();
        System.out.println("---------------------");

        Teacher t = (Teacher) context.getBean("teacher_fang");
        t.gotoSwim();
        System.out.println("---------------------");
        t.stopSwimming();
        System.out.println("---------------------");
    }

}