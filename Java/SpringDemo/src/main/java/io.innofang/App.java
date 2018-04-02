package io.innofang;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * Created by Inno Fang on 2018/3/30.
 */
public class App {

    private static ApplicationContext context;

    public static void main(String[] args) {
        context = new ClassPathXmlApplicationContext("spring-beans.xml");

        HelloWorld hw = (HelloWorld) context.getBean("hello_bean");
        hw.printHello();
    }
}
