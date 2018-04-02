package io.innofang.custom_event;

import org.junit.Test;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class CustomEventTest {

    @Test
    public void test() {
        ConfigurableApplicationContext context = new ClassPathXmlApplicationContext("spring-customevent.xml");
        CustomEventPublisher cep = (CustomEventPublisher) context.getBean("custom_event_publisher");
        cep.publish();
        cep.publish();
    }

}