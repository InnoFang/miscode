package io.innofang.lexer.model;

/**
 * Created with IntelliJ IDEA
 * Created By Inno Fang
 * Date: 2018/5/21
 * Time: 15:00
 */
public enum TokenType {
    //VAR("VAR"), INTEGER("INTEGER"), LONGINT("LONGINT"), REAL("REAL"), BOOL("BOOL"), IF("IF"),
    //INTEGER_CONST("INTEGER_CONST"), LONGINT_CONST("LONGING_CONST"), REAL_CONST("REAL_CONST"),
    //THEN("THEN"), ELSE("ELSE"), WHILE("WHILE"), DO("DO"), FOR("FOR"), BEGIN("BEGIN"), ID("ID"),
    //END("END"), AND("AND"), OR("OR"), PLUS("+"), MINUS("-"), MUL("*"), DIV("/"),
    //ASSIGN(":="), LESS("<"), GREATER(">"), UNEQUAL("<>"), GEQUAL(">="), LEQUAL("<="),
    //EQUAL("=="), SEMI(";"), COLON(":"), LPAREN("("), RPAREN(")"), COMMA(","), EOF("EOF");

    VAR("关键字：VAR"), INTEGER("声明常量类型：INTEGER"), LONGINT("声明常量类型：LONGINT"), REAL("声明常量类型：REAL"),
    BOOL("声明常量类型：BOOL"), IF("关键字：IF"), INTEGER_CONST("INTEGER 变量值"), LONGINT_CONST("LONGING 变量值"),
    REAL_CONST("REAL 变量值"), THEN("关键字：THEN"), ELSE("关键字：ELSE"), WHILE("关键字：WHILE"), DO("关键字：DO"),
    FOR("FOR"), BEGIN("BEGIN"), ID("标识符"), END("关键字：END"), AND("逻辑与"), OR("逻辑或"), PLUS("二元运算符 +"),
    MINUS("二元运算符 -"), MUL("二元运算符 *"), DIV("二元运算符 /"), ASSIGN("赋值符号 :="), LESS("小于号 <"),
    GREATER("大于号 >"), UNEQUAL("不等于号 <>"), GEQUAL("大于等于 >="), LEQUAL("小于等于 <="), EQUAL("等于 =="),
    SEMI("分号 ;"), COLON("冒号 :"), LPAREN("左括号 ("), RPAREN("右括号 )"), COMMA("逗号 ,"), EOF("EOF");

    String type;

    TokenType(String type) {
        this.type = type;
    }

    @Override
    public String toString() {
        return type;
    }
}
