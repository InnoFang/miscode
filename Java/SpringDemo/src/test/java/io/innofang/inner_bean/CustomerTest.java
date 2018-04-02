package io.innofang.inner_bean;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * Created by Inno Fang on 2018/3/30.
 */
public class CustomerTest {
    @Test
    public void printCustomer(){
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-inner-bean.xml");
        Customer c = (Customer) context.getBean("customer_bean");
        System.out.println(c.toString());
    }
}