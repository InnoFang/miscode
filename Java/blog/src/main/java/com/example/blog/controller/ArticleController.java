package com.example.blog.controller;

import com.example.blog.domain.Article;
import com.example.blog.domain.Result;
import com.example.blog.enums.ResultEnum;
import com.example.blog.repository.ArticleRepository;
import com.example.blog.utils.ResultUtil;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * Created by Inno Fang on 2018/4/25.
 */
@RestController
public class ArticleController {

    @Autowired
    private ArticleRepository articleRepository;

    @GetMapping(value = "/article_list")
    public Result<List<Article>> getAllArticles() {
        List<Article> articles = articleRepository.findAll();
        return ResultUtil.success(ResultEnum.GET_ARTICLE_LIST, articles);
    }

}
