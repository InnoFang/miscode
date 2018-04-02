package io.innofang.event_handler;

import org.springframework.context.ApplicationListener;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.event.ContextStartedEvent;
import org.springframework.context.event.ContextStoppedEvent;

/**
 * Created by Inno Fang on 2018/4/1.
 */
@Configuration
public class ExampleConfig {

    @Bean
    public Example getExample() {
        return new Example();
    }


    @Bean
    public ApplicationListener<ContextStartedEvent> startEventHandler() {
        return new ApplicationListener<ContextStartedEvent>() {
            public void onApplicationEvent(ContextStartedEvent contextStartedEvent) {
                System.out.println("ContextStartedEvent Received");
            }
        };
    }

    @Bean
    public ApplicationListener<ContextStoppedEvent> stopEventHandler() {
        return new ApplicationListener<ContextStoppedEvent>() {
            public void onApplicationEvent(ContextStoppedEvent contextStoppedEvent) {
                System.out.println("ContextStoppedEvent Received");
            }
        };
    }
}
