package io.innofang.demo.repository;

import io.innofang.demo.domain.Girl;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public interface GirlRepository extends JpaRepository<Girl, Integer>{

    // 通过年龄来查询
    public List<Girl> findByAge(Integer age);
}
