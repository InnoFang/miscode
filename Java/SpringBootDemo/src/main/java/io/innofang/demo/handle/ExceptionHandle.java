package io.innofang.demo.handle;

import io.innofang.demo.exception.GirlException;
import io.innofang.demo.domain.Result;
import io.innofang.demo.utils.ResultUtil;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.ResponseBody;

/**
 * Created by Inno Fang on 2018/4/2.
 */

@ControllerAdvice
public class ExceptionHandle {

    @ExceptionHandler(value = Exception.class)
    @ResponseBody
    public Result handle(Exception e) {
        if (e instanceof GirlException) {
            GirlException exception = (GirlException) e;
            return ResultUtil.error(exception.getCode(), e.getMessage());
        }
        return ResultUtil.error(-1, "未知错误");
    }
}
