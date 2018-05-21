package io.innofang.lexer.utils;

import io.innofang.lexer.model.Token;
import io.innofang.lexer.model.TokenType;

import java.util.HashMap;

/**
 * Created with IntelliJ IDEA
 * Created By Inno Fang
 * Date: 2018/5/21
 * Time: 15:15
 */
public class Lexer {

    private char[] text;
    private int pos;
    private Character currentChar;

    private HashMap<String, Token> keywords = new HashMap<>();

    {
        keywords.put("var", new Token(TokenType.VAR, "var"));
        keywords.put("integer", new Token(TokenType.INTEGER, "integer"));
        keywords.put("longint", new Token(TokenType.LONGINT, "longint"));
        keywords.put("real", new Token(TokenType.REAL, "real"));
        keywords.put("bool", new Token(TokenType.BOOL, "bool"));
        keywords.put("if", new Token(TokenType.IF, "if"));
        keywords.put("then", new Token(TokenType.THEN, "then"));
        keywords.put("else", new Token(TokenType.ELSE, "else"));
        keywords.put("while", new Token(TokenType.WHILE, "while"));
        keywords.put("do", new Token(TokenType.DO, "do"));
        keywords.put("for", new Token(TokenType.FOR, "for"));
        keywords.put("begin", new Token(TokenType.BEGIN, "begin"));
        keywords.put("end", new Token(TokenType.END, "end"));
        keywords.put("and", new Token(TokenType.AND, "and"));
        keywords.put("or", new Token(TokenType.OR, "or"));
    }


    public Lexer(String text) {
        this.text = text.toCharArray();
        this.pos = 0;
        assert !text.isEmpty();
        this.currentChar = this.text[pos];
    }

    private void advance() {
        pos += 1;
        if (pos > text.length - 1) {
            currentChar = null;
        } else {
            currentChar = text[pos];
        }
    }

    private void skipWhitespace() {
        while (currentChar != null && isSpace(currentChar)) {
            advance();
        }
    }

    private Character peek() {
        int peekPos = pos + 1;
        if (peekPos > text.length - 1) {
            return null;
        } else {
            return text[peekPos];
        }
    }

    private Token number() {
        StringBuilder result = new StringBuilder();
        while (null != currentChar && isDigit(currentChar)) {
            result.append(currentChar);
            advance();
        }
        if (null != currentChar && currentChar == '.') {
            result.append(currentChar);
            advance();
            while (null != currentChar && isDigit(currentChar)) {
                result.append(currentChar);
                advance();
            }
            return new Token(TokenType.REAL_CONST, Double.valueOf(result.toString()));
        } else {
            String tmp = result.toString();
            if (tmp.length() >= 10 && tmp.compareTo(String.valueOf(Integer.MAX_VALUE)) > 0) {
                return new Token(TokenType.LONGINT_CONST, Long.valueOf(tmp));
            }
            return new Token(TokenType.INTEGER_CONST, Integer.valueOf(tmp));
        }

    }


    private Token identifier() {
        StringBuilder result = new StringBuilder();
        while (null != currentChar && isAlphaOrNum(currentChar)) {
            result.append(currentChar);
            advance();
        }
        return keywords.getOrDefault(result.toString(), new Token(TokenType.ID, result));
    }

    public Token getNextToken() {
        while (null != currentChar) {
            if (isSpace(currentChar)) {
                skipWhitespace();
                continue;
            }
            if (isAlpha(currentChar)) {
                return identifier();
            }
            if (isDigit(currentChar)) {
                return number();
            }
            if (currentChar == ':' && null != peek() && peek() == '=') {
                advance();
                advance();
                return new Token(TokenType.ASSIGN, ":=");
            }
            if (currentChar == ':') {
                advance();
                return new Token(TokenType.COLON, ":");
            }
            if (currentChar == '<' && null != peek() && peek() == '=') {
                advance();
                advance();
                return new Token(TokenType.LEQUAL, "<=");
            }
            if (currentChar == '<' && null != peek() && peek() == '>') {
                advance();
                advance();
                return new Token(TokenType.UNEQUAL, "<>");
            }
            if (currentChar == '<') {
                advance();
                return new Token(TokenType.LESS, "<");
            }
            if (currentChar == '>' && null != peek() && peek() == '=') {
                advance();
                advance();
                return new Token(TokenType.GEQUAL, ">=");
            }
            if (currentChar == '>') {
                advance();
                return new Token(TokenType.GREATER, ">");
            }
            if (currentChar == '=' && null != peek() && peek() == '=') {
                advance();
                advance();
                return new Token(TokenType.EQUAL, "==");
            }
            if (currentChar == ';') {
                advance();
                return new Token(TokenType.SEMI, ";");
            }
            if (currentChar == ',') {
                advance();
                return new Token(TokenType.COMMA, ",");
            }
            if (currentChar == '+') {
                advance();
                return new Token(TokenType.PLUS, "+");
            }
            if (currentChar == '-') {
                advance();
                return new Token(TokenType.MINUS, "-");
            }
            if (currentChar == '*') {
                advance();
                return new Token(TokenType.MUL, "*");
            }
            if (currentChar == '/') {
                advance();
                return new Token(TokenType.DIV, "/");
            }
            if (currentChar == '(') {
                advance();
                return new Token(TokenType.LPAREN, "(");
            }
            if (currentChar == ')') {
                advance();
                return new Token(TokenType.RPAREN, ")");
            }
            throw new IllegalArgumentException("Invalid character");
        }
        return new Token(TokenType.EOF, "EOF");
    }

    private boolean isDigit(Character c) {
        return (c >= '0' && c <= '9');
    }

    private boolean isAlpha(Character c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    private boolean isSpace(Character c) {
        return c == '\n' || c == ' ' || c == '\r' || c == '\t';
    }

    private boolean isAlphaOrNum(Character c) {
        return isAlpha(c) || isDigit(c);
    }
}
