#pragma once

enum exprType{
    BOOL = 1,
    BYTE,
    UINT,
    INT,
    NUMBER,
    CHAR,
    STRING,
    NULLEXPR
};

struct Expr{
    exprType type;
    string value;
};

bool isExprValid(TokenType t){
    return(
        t == int_lit || 
        t == TokenType::plus || 
        t == TokenType::minus ||
        t == prod ||
        t == division ||
        t == remainder ||
        t == str_lit || 
        t == true_k || t == false_k ||
        t == char_lit ||
        t == num_lit ||
        t == TokenType::greater ||
        t == greater_eq ||
        t == is_equal ||
        t == TokenType::less ||
        t == less_eq ||
        t == and_s ||
        t == or_s ||
        t == not_equal ||
        t == id
        
    );
}

const Expr nullExpr = {NULLEXPR, ""}; 
const Token trueToken = {true_k, "1"};
const Token falseToken = {false_k, "0"};