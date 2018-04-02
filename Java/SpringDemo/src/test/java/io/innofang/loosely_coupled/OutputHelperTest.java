package io.innofang.loosely_coupled;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/3/30.
 */
public class OutputHelperTest {

    @Test
    public void generateOutput() {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-output.xml");
        OutputHelper oh = (OutputHelper) context.getBean("output_helper");
        oh.generateOutput();
    }
}