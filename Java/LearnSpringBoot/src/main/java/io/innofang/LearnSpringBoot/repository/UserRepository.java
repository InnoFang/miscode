package io.innofang.LearnSpringBoot.repository;

import io.innofang.LearnSpringBoot.domain.User;
import org.springframework.stereotype.Repository;

import java.util.Collection;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Created by Inno Fang on 2018/4/7.
 *
 * {@link User}
 *
 * {@link Repository}
 */

@Repository
public class UserRepository {

    private ConcurrentHashMap<Integer, User> repository
            = new ConcurrentHashMap<>();

    private final static AtomicInteger idGenerator
            = new AtomicInteger();

    /**
     * 保存对象
     * @param user {@link User} 对象
     * @return 如果保存成功，返回<code>true</code>
     *          否则，返回<code>false</code>
     */
    public boolean save(User user) {
        // id 自增长
        Integer id = idGenerator.incrementAndGet();
        user.setId(id);
        return repository.put(id, user) == null;
    }

    /**
     * 返回所有用户列表
     * @return
     */
    public Collection<User> findAll() {
        return repository.values();
    }
}
