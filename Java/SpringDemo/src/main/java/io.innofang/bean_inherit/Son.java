package io.innofang.bean_inherit;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class Son extends Father{
    private int age;

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "Son{" +
                "lastName='" + getLastName() + '\'' +
                ", firstName='" + getFirstName() + '\'' +
                ", age=" + age +
                '}';
    }
}
