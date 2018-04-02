package io.innofang.component_scan.service;

import io.innofang.spring_auto.service.CustomerService;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/3/30.
 */
public class CustomerServiceTest {

    @Test
    public void testScan(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-scan.xml");
        CustomerService cs = (CustomerService) context.getBean("customerService");
        System.out.println(cs);
    }
}