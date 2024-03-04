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
    any value;
};

struct BinaryExpr{
    any left;
    any right;
    TokenType op;
};

bool isExprValid(TokenType t){
    return(
        t == int_lit || 
        t == TokenType::plus || 
        t == TokenType::minus ||
        t == prod ||
        t == division ||
        t == remainder
        
    );
}

const Expr nullExpr = {NULLEXPR, ""};