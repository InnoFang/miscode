package io.innofang.LearnSpringBoot.config;

import com.sun.deploy.nativesandbox.comm.Response;
import io.innofang.LearnSpringBoot.domain.User;
import io.innofang.LearnSpringBoot.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.reactive.function.server.RequestPredicates;
import org.springframework.web.reactive.function.server.RouterFunction;
import org.springframework.web.reactive.function.server.RouterFunctions;
import org.springframework.web.reactive.function.server.ServerResponse;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

import java.util.Collection;

/**
 * Created by Inno Fang on 2018/4/7.
 */

@Configuration
public class RouterFunctionConfiguration {

    /**
     * Servlet
     *  请求接口：ServletRequest 或者 HttpServletRequest
     *  响应接口：ServletResponse 或者 HttpServletResponse
     *
     *  Spring 5.0 重新定义了服务请求和响应接口
     *  请求接口：ServerRequest
     *  响应接口：ServerResponse
     *  既可以支持 Servlet 规范，也可以支持自定义，比如 Netty（Web Server）
     *
     *  定义 Get 请求，并且返回所有的用户对象 URL：/person/find/all
     *  Flux 是 0 - N 个对象集合
     *  Mono 是 0 - 1 个对象集合
     *  Reactive 中的 Flux 或者 Mono 它是异步处理（非阻塞）
     *  集合对象基本上是同步处理（阻塞）
     *  Flux 或者 Mono 都是 Publisher
     */
    @Bean
    @Autowired
    public RouterFunction<ServerResponse> personFindAll(UserRepository userRepository) {
        return RouterFunctions.route(RequestPredicates.GET("/person/find/all"),
                request -> {
                    // 返回所有的用户对象
                    Collection<User> users = userRepository.findAll();
                    Flux<User> userFlux = Flux.fromIterable(users);
                    return ServerResponse.ok().body(userFlux, User.class);                });
    }
}
