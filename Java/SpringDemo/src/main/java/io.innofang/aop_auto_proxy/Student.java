package io.innofang.aop_auto_proxy;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public class Student {

    private String name;

    public void gotoWalk() {
        System.out.println(name + " go to walk.");
    }

    public void stopWalking() {
        System.out.println(name + " stop walking.");
    }

    public void setName(String name) {
        this.name = name;
    }
}
