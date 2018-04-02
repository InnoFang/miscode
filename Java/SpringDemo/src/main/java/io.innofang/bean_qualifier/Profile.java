package io.innofang.bean_qualifier;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class Profile {

    @Autowired
    @Qualifier("student1")
    private Student student;

    public Profile(){
        System.out.println("Profile constructor.");
    }

    public void print() {
        System.out.println(student);
    }
}
