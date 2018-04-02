package io.innofang.bean_inherit;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class InheritTest {

    @Test
    public void test() {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-inherit.xml");

        Father father = (Father) context.getBean("father");
        Son son = (Son) context.getBean("son");
        System.out.println(father);
        System.out.println(son);
    }

}