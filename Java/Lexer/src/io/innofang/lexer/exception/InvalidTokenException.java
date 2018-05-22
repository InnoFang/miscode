package io.innofang.lexer.exception;

/**
 * Created with IntelliJ IDEA
 * Created By Inno Fang
 * Date: 2018/5/22
 * Time: 20:07
 */
public class InvalidTokenException extends IllegalArgumentException {

    public InvalidTokenException(Character tokenValue) {
        super("Invalid Token: \"" + tokenValue + "\"");
    }
}
