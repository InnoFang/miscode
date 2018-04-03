package io.innofang.demo.controller;

import io.innofang.demo.aspect.HttpAspect;
import io.innofang.demo.domain.Girl;
import io.innofang.demo.domain.Result;
import io.innofang.demo.repository.GirlRepository;
import io.innofang.demo.service.GirlService;
import io.innofang.demo.utils.ResultUtil;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.util.List;

/**
 * Created by Inno Fang on 2018/4/2.
 */
@RestController
public class GirlController {

    private final static Logger logger = LoggerFactory.getLogger(GirlController.class);

    @Autowired
    private GirlRepository girlRepository;

    @Autowired
    private GirlService girlService;

    /**
     * 查询所有数据
     *
     * @return
     */
    @GetMapping(value = "/girls")
    public List<Girl> girlList() {
        return girlRepository.findAll();
    }

    /**
     * 添加一条数据
     *
     * @return
     */
//    @PostMapping(value = "/girls")
//    public Girl girlAdd(@RequestParam("cupSize") String cupSize,
//                        @RequestParam("age") int age) {
//        Girl girl = new Girl();
//        girl.setCupSize(cupSize);
//        girl.setAge(age);
//        return girlRepository.save(girl);
//    }
    @PostMapping(value = "/girls")
    public Result<Girl> girlAdd(@Valid Girl girl, BindingResult bindingResult) {
        if (bindingResult.hasErrors()) {
            return ResultUtil.error(1, bindingResult.getFieldError().getDefaultMessage());
        }
        return ResultUtil.success(girlRepository.save(girl));
    }

    /**
     * 查找一条数据
     * @param id
     * @return
     */
    @GetMapping(value = "/girls/{id}")
    public Girl girlFindOne(@PathVariable("id") int id) {
        return girlRepository.findById(id).get();
    }

    /**
     * 更新一条数据
     * @param id
     * @param cupSize
     * @param age
     * @return
     */
    @PutMapping(value = "/girls/{id}")
    public Girl girlUpdate(@PathVariable("id") int id,
                           @RequestParam("cupSize") String cupSize,
                           @RequestParam("age") int age) {
        Girl girl = new Girl();
        girl.setId(id);
        girl.setAge(age);
        girl.setCupSize(cupSize);
        return girlRepository.save(girl);
    }

    /**
     * 删除一条数据
     * @param id
     */
    @DeleteMapping(value = "/girls/{id}")
    public void girlDelete(@PathVariable("id") int id) {
        girlRepository.deleteById(id);
    }

    /**
     * 通过年龄查询
     * @param age
     * @return
     */
    @GetMapping(value = "/girls/age/{age}")
    public List<Girl> girlListByAge(@PathVariable("age") Integer age){
        return girlRepository.findByAge(age);
    }

    @PostMapping(value = "/girls/two")
    public void girlTwo(){
        girlService.insertTwo();
    }

    @GetMapping(value = "girls/getAge/{id}")
    public void getAge(@PathVariable("id") Integer id) throws Exception {
        girlService.getAge(id);
    }
}
