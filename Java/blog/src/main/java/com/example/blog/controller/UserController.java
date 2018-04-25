package com.example.blog.controller;

import com.example.blog.domain.Result;
import com.example.blog.domain.User;
import com.example.blog.enums.ResultEnum;
import com.example.blog.repository.UserRepository;
import com.example.blog.utils.ResultUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

/**
 * Created by Inno Fang on 2018/4/25.
 */
@RestController
public class UserController {

    @Autowired
    private UserRepository userRepository;

    @PostMapping(value = "/user/sign_up")
    public Result singUp(@RequestParam("user_name") String username,
                         @RequestParam("user_password") String password) {
        if (null != userRepository.findByUserName(username)) {
            return ResultUtil.error(ResultEnum.USER_DUPLICATE);
        }
        User user = new User();
        user.setUserName(username);
        user.setUserPassword(password);
        userRepository.save(user);
        return ResultUtil.success(ResultEnum.SIGN_UP);
    }

    @PostMapping(value = "/user/sign_in")
    public Result signIn(@RequestParam("user_name") String usernamne,
                         @RequestParam("user_password") String password) {
        User user = userRepository.findByUserName(usernamne);
        if (null == user) {
            return ResultUtil.error(ResultEnum.USER_MISSED);
        }
        if (!user.getUserPassword().equals(password)) {
            return ResultUtil.error(ResultEnum.WRONG_PASSWORD);
        }
        return ResultUtil.success(ResultEnum.SIGN_IN);
    }

}
