package io.innofang.aop_aspectj;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public class AspectjTest {

    @Test
    public void test() {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-aop-aspectj.xml");
        ICustomer customer = (ICustomer) context.getBean("customer");

        customer.addCustomer();

        System.out.println("+--------------------+");

        customer.deleteCustomer();
    }

}