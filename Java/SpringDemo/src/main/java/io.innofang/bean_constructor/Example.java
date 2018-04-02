package io.innofang.bean_constructor;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class Example {
    private Message message;

    public Example(Message message) {
        System.out.println("example initialization.");
        this.message = message;
    }

    public void printMessage() {
        System.out.println("Message: " + message);
    }
}
