package io.innofang.lexer.model;

/**
 * Created with IntelliJ IDEA
 * Created By Inno Fang
 * Date: 2018/5/21
 * Time: 14:57
 */
public class Token {

    private TokenType type;
    private Object value;

    public Token(TokenType type, Object value) {
        this.type = type;
        this.value = value;
    }

    public TokenType getType() {
        return type;
    }

    public Object getValue() {
        return value;
    }

    @Override
    public String toString() {
        return String.format("Token(%s, %s)", type, value);
    }
}
