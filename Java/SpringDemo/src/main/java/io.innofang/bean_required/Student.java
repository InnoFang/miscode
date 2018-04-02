package io.innofang.bean_required;

import org.springframework.beans.factory.annotation.Required;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class Student {
    private String name;
    private int age;

    public String getName() {
        return name;
    }

    @Required
    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    @Required
    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }
}
