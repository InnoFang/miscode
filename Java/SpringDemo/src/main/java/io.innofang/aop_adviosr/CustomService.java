package io.innofang.aop_adviosr;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public class CustomService {

    private String name;
    private String url;

    public void printName() {
        System.out.println("Custom name: " + name);
    }

    public void setName(String name) {
        this.name = name;
    }

    public void printUrl() {
        System.out.println("Custom url: " + url);
    }

    public void setUrl(String url) {
        this.url = url;
    }

    public void printThrowException() {
        throw new IllegalArgumentException();
    }
}
