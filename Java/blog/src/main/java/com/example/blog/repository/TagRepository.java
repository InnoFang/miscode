package com.example.blog.repository;

import com.example.blog.domain.Article;
import com.example.blog.domain.Tag;
import org.springframework.data.jpa.repository.JpaRepository;

/**
 * Created by Inno Fang on 2018/4/25.
 */
public interface TagRepository extends JpaRepository<Tag, Long> {
}
