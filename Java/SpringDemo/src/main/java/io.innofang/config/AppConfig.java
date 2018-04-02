package io.innofang.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

/**
 * Created by Inno Fang on 2018/3/30.
 */

@Configuration
public class AppConfig {

    @Bean(name = "animal")
    public IAnimal getAnimal() {
        return new Dog();
    }
}
