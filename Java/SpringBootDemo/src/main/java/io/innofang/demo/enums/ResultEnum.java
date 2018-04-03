package io.innofang.demo.enums;

/**
 * Created by Inno Fang on 2018/4/2.
 */
public enum  ResultEnum {
    UNKNOWN_ERROR(-1, "未知错误"),
    SUCCESS(0, "成功"),
    PRIMARY_SCHOOL(100, "还在上小学吧"),
    MIDDLE_SCHOOL(101, "还在上初中吧");

    private Integer code;
    private String msg;

    ResultEnum(Integer code, String msg) {
        this.code = code;
        this.msg = msg;
    }

    public Integer getCode() {
        return code;
    }

    public String getMsg() {
        return msg;
    }
}
