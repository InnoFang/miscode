package io.innofang.spring_auto.service;

import io.innofang.collections.Customer;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/3/30.
 */
public class CustomerServiceTest {

    @Test
    public void testAuto(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-auto.xml");
        CustomerService cs = (CustomerService) context.getBean("customer_service");
        System.out.println(cs);
    }
}