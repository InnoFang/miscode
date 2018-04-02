package io.innofang.post_processor;

import org.junit.Test;
import org.springframework.context.support.AbstractApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class MessageTest {

    @Test
    public void test() {
        AbstractApplicationContext context = new ClassPathXmlApplicationContext("spring-postprocessor.xml");
        Message m = (Message) context.getBean("example");
        System.out.println(m.getMessage());
        context.registerShutdownHook();
    }

}