package io.innofang.bean_qualifier;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class ProfileTest {

    @Test
    public void test() {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-qualifier.xml");
        Profile profile = (Profile) context.getBean("profile");
        profile.print();
    }

}