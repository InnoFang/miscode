package io.innofang.inner_bean;

/**
 * Created by Inno Fang on 2018/3/30.
 */
public class Customer {
    private Person person;

    public Customer(Person person) {
        this.person = person;
    }
    public Customer(){}

    public void setPerson(Person person) {
        this.person = person;
    }

    @Override
    public String toString() {
        return "Customer{" +
                "person=" + person +
                '}';
    }
}
