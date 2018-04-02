package io.innofang.aop_aspectj;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public interface ICustomer {
    void addCustomer();
    void deleteCustomer();
    String addCustomerReturnValue();
    void addCustomerThrowException() throws Exception;
    void addCustomerAround(String name);

}
