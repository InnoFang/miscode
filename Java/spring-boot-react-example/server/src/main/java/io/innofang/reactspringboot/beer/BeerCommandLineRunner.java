package io.innofang.reactspringboot.beer;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;

import java.util.stream.Stream;

/**
 * Created by Inno Fang on 2018/4/9.
 */

@Component
public class BeerCommandLineRunner implements CommandLineRunner {

    private final BeerRepository repository;

    public BeerCommandLineRunner(BeerRepository repository) {
        this.repository = repository;
    }

    @Override
    public void run(String... args) throws Exception {
        Stream.of("Kentucky Brunch Brand Stout", "Good Morning", "Very Hazy", "King Julius",
                "Budweiser", "Coors Light", "PBR").forEach(name ->
        repository.save(new Beer(name)));
        repository.findAll().forEach(System.out::println);
    }
}
