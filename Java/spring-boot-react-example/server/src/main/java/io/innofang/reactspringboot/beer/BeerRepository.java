package io.innofang.reactspringboot.beer;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.rest.core.annotation.RepositoryRestResource;

/**
 * Created by Inno Fang on 2018/4/9.
 */

@RepositoryRestResource
public interface BeerRepository extends JpaRepository<Beer, Long>{
}
