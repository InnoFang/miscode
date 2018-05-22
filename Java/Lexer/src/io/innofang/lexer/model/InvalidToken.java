package io.innofang.lexer.model;

import java.util.ArrayList;
import java.util.List;

/**
 * Created with IntelliJ IDEA
 * Created By Inno Fang
 * Date: 2018/5/22
 * Time: 20:17
 */
public class InvalidToken extends Token {

    Object value;

    List<String> keywords = new ArrayList<>();

    {
        keywords.add("+");
        keywords.add("-");
        keywords.add("*");
        keywords.add("/");
        keywords.add(":=");
        keywords.add("<");
        keywords.add(">");
        keywords.add("<>");
        keywords.add(">=");
        keywords.add("<=");
        keywords.add("==");
        keywords.add(";");
        keywords.add("(");
        keywords.add(")");
        keywords.add(",");
        keywords.add(":");
    }

    public InvalidToken(Object value) {
        super(TokenType.INVALID, value);
        this.value = value;
    }

    @Override
    public TokenType getType() {
        TokenType type = TokenType.INVALID;
        StringBuilder tips = new StringBuilder();
        keywords.forEach(k -> {
            if (k.contains(value.toString())) tips.append(k).append(",");
        });

        String content = "不合法符号：" + value;
        if (tips.length() > 0) {
            content += "\n相似符号：" + tips.substring(0, tips.length() - 1);
        }
        type.setContent(content);
        return type;
    }
}
