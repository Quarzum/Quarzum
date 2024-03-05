#pragma once

enum exprType{
    INT = 1,
    NUMBER,
    STRING,
    CHAR,
    BOOL,
    BYTE,
    UINT,
    NULLEXPR
};

struct Expr{
    exprType type;
    Token value;
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
        t == num_lit
        
    );
}

const Expr nullExpr = {NULLEXPR,Token{err, ""}}; 