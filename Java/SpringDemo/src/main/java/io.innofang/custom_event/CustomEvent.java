package io.innofang.custom_event;

import org.springframework.context.ApplicationContext;
import org.springframework.context.ApplicationEvent;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class CustomEvent extends ApplicationEvent {

    public CustomEvent(Object source) {
        super(source);
    }

    @Override
    public String toString() {
        return "CustomEvent{}";
    }
}
