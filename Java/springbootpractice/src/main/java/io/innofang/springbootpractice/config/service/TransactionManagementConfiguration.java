package io.innofang.springbootpractice.config.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.jdbc.datasource.DataSourceTransactionManager;
import org.springframework.transaction.PlatformTransactionManager;
import org.springframework.transaction.annotation.EnableTransactionManagement;
import org.springframework.transaction.annotation.TransactionManagementConfigurer;

import javax.sql.DataSource;

/**
 * Created by Inno Fang on 2018/4/8.
 *
 * 对标spring-service里面的transactionManager
 * 继承TransactionManagementConfigurer是因为开启annotation-driven
 */

// 首先使用注解 @EnableTransactionManagement 开启事务支持后
// 在Service方法上添加注解 @Transactional 便可
@Configuration
@EnableTransactionManagement
public class TransactionManagementConfiguration implements TransactionManagementConfigurer {

    // 注入DataSourceConfiguration里边的dataSource,通过createDataSource()获取
    @Autowired
    private DataSource dataSource;

    /**
     * 关于事务管理，需要返回PlatformTransactionManager的实现
     */
    @Override
    public PlatformTransactionManager annotationDrivenTransactionManager() {
        return new DataSourceTransactionManager(dataSource);
    }
}
