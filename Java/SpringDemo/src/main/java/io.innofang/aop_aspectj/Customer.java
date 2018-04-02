package io.innofang.aop_aspectj;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public class Customer implements ICustomer {
    public void addCustomer() {
        System.out.println("addCustomer() is running...");
    }

    public void deleteCustomer() {
        System.out.println("deleteCustomer() is running...");
    }

    public String addCustomerReturnValue() {
        System.out.println("addCustomerReturnValue() is running...");
        return "sth.";
    }

    public void addCustomerThrowException() throws Exception {
        System.out.println("addCustomerThrowException() is running ...");
        throw new Exception("Generic Error");
    }

    public void addCustomerAround(String name) {
        System.out.println("addCustomerAround() is running ,args:"+name);
    }
}
