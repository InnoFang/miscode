package io.innofang.bean_required;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class StudentTest {

    @Test
    public void test() {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-required.xml");
        Student student = (Student) context.getBean("student");
        System.out.println(student);
    }

}