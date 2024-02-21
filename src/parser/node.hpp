#pragma once
using tokens::TokenType;
enum exprType{
    STRING,
    INT,
    NUMBER,
    BYTE,
    BOOL,
    CHAR,
    NULLEXPR
};

struct Expr{
    exprType type;
    any value;
};

struct BinaryExpr{
    any left;
    any right;
    TokenType op;
};

bool isExprValid(TokenType t){
    return(
        t == TokenType::int_lit || 
        t == TokenType::plus || 
        t == TokenType::minus ||
        t == TokenType::prod ||
        t == TokenType::division ||
        t == TokenType::remainder
        
    );
}

Expr nullExpr = {NULLEXPR, ""};