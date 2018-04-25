package com.example.blog.repository;

import com.example.blog.domain.User;
import org.springframework.data.jpa.repository.JpaRepository;

/**
 * Created by Inno Fang on 2018/4/25.
 */
public interface UserRepository extends JpaRepository<User, Long> {
    User findByUserName(String username);
}
