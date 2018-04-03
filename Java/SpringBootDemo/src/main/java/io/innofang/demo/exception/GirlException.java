package io.innofang.demo.exception;

import io.innofang.demo.enums.ResultEnum;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public class GirlException extends RuntimeException {

    private Integer code;

    public GirlException(ResultEnum resultEnum){
        super(resultEnum.getMsg());
        this.code  = resultEnum.getCode();
    }

    public Integer getCode() {
        return code;
    }

    public void setCode(Integer code) {
        this.code = code;
    }
}
