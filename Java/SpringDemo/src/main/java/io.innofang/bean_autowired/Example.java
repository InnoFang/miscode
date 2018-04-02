package io.innofang.bean_autowired;

import org.springframework.beans.factory.annotation.Autowired;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class Example {

    @Autowired
    private Person person;


    public void doSomething() {

        person.say();
        person.walk();
    }

}
