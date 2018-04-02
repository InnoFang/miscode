package io.innofang.aop_auto_proxy;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public class Teacher {

    private String name;

    public void gotoSwim() {
        System.out.println(name + " go to swim.");
    }

    public void stopSwimming() {
        System.out.println(name + " stop swimming.");
    }

    public void setName(String name) {
        this.name = name;
    }
}
