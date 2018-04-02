package io.innofang.bean_byConstructor;

/**
 * Created by Inno Fang on 2018/4/1.
 */
public class Example {

    private Person person;
    private String name;
    public Example(Person person, String name) {
        this.person = person;
        this.name = name;
    }

    public Person getPerson() {
        return person;
    }

    public void setPerson(Person person) {
        this.person = person;
    }

    public void doSomething() {
        System.out.println(name);
        person.say();
        person.walk();
    }

}
