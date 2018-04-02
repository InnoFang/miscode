package io.innofang.collections;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/3/30.
 */
public class CustomerTest {

    @Test
    public void testCollections() {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-collections.xml");
        Customer c = (Customer) context.getBean("customer_bean");
        System.out.println(c.getList().toString());
        System.out.println(c.getSet().toString());
        System.out.println(c.getMap().toString());
        System.out.println(c.getPros().toString());
    }
}