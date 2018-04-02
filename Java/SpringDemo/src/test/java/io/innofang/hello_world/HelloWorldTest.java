package io.innofang.hello_world;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public class HelloWorldTest {

    @Test
    public void test() {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-beans.xml");

        HelloWorld hw = (HelloWorld) context.getBean("hello_bean");
        hw.printHello();
    }
}