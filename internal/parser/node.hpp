#pragma once

enum exprType{
    STRING,
    INT,
    NUMBER,
    BYTE,
    BOOL,
    CHAR,
    NULLEXPR
};
struct IntExpr{
    Token token;
};

struct Expr{
    exprType type;
    IntExpr value;
};



int getPrecedence(Token t){
    switch (t.type)
    {
    case TokenType::prod:
    case TokenType::division:
    case TokenType::remainder:
        return 1;
    case TokenType::plus:
    case TokenType::minus:
        return 2;
    }
}