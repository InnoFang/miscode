package io.innofang.lexer.model;

import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * Created with IntelliJ IDEA
 * Created By Inno Fang
 * Date: 2018/5/21
 * Time: 20:10
 */
public class TokenItem extends Token {

    private final StringProperty value;
    private final StringProperty type;

    public TokenItem(Token token) {
        this(token.getType(), token.getValue());
    }

    public TokenItem(TokenType type, Object value) {
        super(type, value);
        this.value = new SimpleStringProperty(value.toString());
        this.type = new SimpleStringProperty(type.toString());
    }

    public StringProperty valueProperty() {
        return value;
    }

    public void setValue(String value) {
        this.value.set(value);
    }


    public StringProperty typeProperty() {
        return type;
    }

    public void setType(String type) {
        this.type.set(type);
    }
}
