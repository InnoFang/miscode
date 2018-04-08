package io.innofang.LearnSpringBoot.cotroller;

import io.innofang.LearnSpringBoot.domain.User;
import io.innofang.LearnSpringBoot.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

/**
 * Created by Inno Fang on 2018/4/7.
 */

@RestController
public class UserController {

    private final UserRepository userRepository;

    @Autowired
    public UserController(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    @PostMapping("/person/save")
    public User save(@RequestParam String name) {
        User user = new User();
        user.setName(name);
        if (userRepository.save(user)) {
            System.out.println(String.format("用户对象：%s 保存成功", user));
        }

        return user;
    }
}
