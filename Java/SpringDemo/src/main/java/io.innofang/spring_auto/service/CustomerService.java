package io.innofang.spring_auto.service;

import io.innofang.spring_auto.dao.CustomerDao;

/**
 * Created by Inno Fang on 2018/3/30.
 */
public class CustomerService {

    CustomerDao customerDao;

    public void setCustomerDao(CustomerDao customerDao) {
        this.customerDao = customerDao;
    }

    @Override
    public String toString() {
        return "CustomerService{" +
                "customerDao=" + customerDao +
                '}';
    }
}
