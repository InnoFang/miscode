package io.innofang.demo.service;

import io.innofang.demo.enums.ResultEnum;
import io.innofang.demo.exception.GirlException;
import io.innofang.demo.domain.Girl;
import io.innofang.demo.repository.GirlRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;


/**
 * Created by Inno Fang on 2018/4/2.
 */
@Service
public class GirlService {

    @Autowired
    private GirlRepository girlRepository;

    @Transactional
    public void insertTwo(){
        Girl girlA = new Girl();
        girlA.setCupSize("A");
        girlA.setAge(18);
        girlRepository.save(girlA);
        Girl girlB = new Girl();
        girlB.setCupSize("B");
        girlB.setAge(18);
        girlRepository.save(girlB);
    }

    public void getAge(Integer id) throws Exception{
        Girl girl = girlRepository.findById(id).get();
        Integer age = girl.getAge();
        if (age < 10) {
            throw new GirlException(ResultEnum.PRIMARY_SCHOOL);
        } else if (age < 16){
            throw new GirlException(ResultEnum.MIDDLE_SCHOOL);
        }
    }
}
