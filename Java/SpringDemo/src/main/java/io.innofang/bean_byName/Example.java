package io.innofang.bean_byName;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class Example {

    private Person person;

    public Person getPerson() {
        return person;
    }

    public void setPerson(Person person) {
        this.person = person;
    }

    public void doSomething() {
        person.say();
        person.walk();
    }

}
