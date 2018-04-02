package io.innofang.custom_event;

import org.springframework.context.ApplicationListener;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class CustomEventHandler implements ApplicationListener<CustomEvent> {

    public void onApplicationEvent(CustomEvent customEvent) {
        System.out.println(customEvent.toString());
    }
}
