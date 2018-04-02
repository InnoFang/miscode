package io.innofang.bean_byName;

import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class ExampleTest {

    @Test
    public void test() {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-byName.xml");
        Example example = (Example) context.getBean("example");
        example.doSomething();
    }

}