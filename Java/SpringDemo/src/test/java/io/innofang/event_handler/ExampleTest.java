package io.innofang.event_handler;

import org.junit.Test;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class ExampleTest {

    @Test
    public void test() {
        ConfigurableApplicationContext context = new AnnotationConfigApplicationContext(ExampleConfig.class);
        Example example = context.getBean(Example.class);
        example.setMessage("123");

        context.start();
        System.out.println(example.getMessage());
        context.stop();
    }

}