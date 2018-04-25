package com.example.blog.utils;

import com.example.blog.domain.Result;
import com.example.blog.enums.ResultEnum;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Inno Fang on 2018/4/25.
 */
public class ResultUtilTest {

    @Test
    public void success() {
        Result res = ResultUtil.success(ResultEnum.SIGN_IN, "Succeed");
        System.out.println(res);
    }

    @Test
    public void success1() {
        Result res = ResultUtil.success(ResultEnum.SIGN_UP);
        System.out.println(res);
        res = ResultUtil.success(ResultEnum.GET_ARTICLE_LIST);
        System.out.println(res);
    }

    @Test
    public void error() {
        Result res = ResultUtil.error(ResultEnum.UNKNOWN_ERROR);
        System.out.println(res);
    }
}