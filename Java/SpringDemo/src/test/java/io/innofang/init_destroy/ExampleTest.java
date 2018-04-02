package io.innofang.init_destroy;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.AbstractApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class ExampleTest {

    @Test
    public void test() {
        AbstractApplicationContext context = new ClassPathXmlApplicationContext("spring-initdest.xml");
        Example example = (Example) context.getBean("example");
        System.out.println(example.getMessage());
        context.registerShutdownHook();
    }

}