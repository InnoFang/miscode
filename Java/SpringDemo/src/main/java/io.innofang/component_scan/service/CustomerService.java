package io.innofang.component_scan.service;

import io.innofang.component_scan.dao.CustomerDao;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Service;

/**
 * Created by Inno Fang on 2018/3/30.
 */

public class CustomerService {

    @Autowired
    CustomerDao customerDao;

//    public void setCustomerDao(CustomerDao customerDao) {
//        this.customerDao = customerDao;
//    }

    @Override
    public String toString() {
        return "CustomerService{" +
                "customerDao=" + customerDao +
                '}';
    }
}
