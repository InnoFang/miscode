package io.innofang;

/**
 * Created by Inno Fang on 2018/3/30.
 */
public class HelloWorld {
    private String name;

    public void setName(String name) {
        this.name = name;
    }

    public void printHello() {
        System.out.println("Hello " + name);
    }
}
