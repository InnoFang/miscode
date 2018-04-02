package io.innofang.post_processor;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class Message {
    String message;

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public void init() {
        System.out.println("Initial...");
    }

    public void destroy() {
        System.out.println("Destroy...");
    }
}
