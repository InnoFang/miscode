package io.innofang;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/3/30.
 */
public class HelloWorldTest {



    @Test
    public void printHello() {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-beans.xml");
        HelloWorld hw = (HelloWorld) context.getBean("hello_bean");
        hw.printHello();

    }
}