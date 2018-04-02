package io.innofang.init_destroy;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class Example {

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
