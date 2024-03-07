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
        t == TokenType::IntegerLit || 
        t == TokenType::Plus || 
        t == TokenType::Minus ||
        t == TokenType::Product ||
        t == TokenType::Division ||
        t == TokenType::Remainder ||
        t == TokenType::StringLit || 
        t == TokenType::True || t == TokenType::False ||
        t == TokenType::CharLit ||
        t == TokenType::NumberLit||
        t == TokenType::Greater ||
        t == TokenType::GreaterEq ||
        t == TokenType::IsEqual ||
        t == TokenType::Lower ||
        t == TokenType::LowerEq ||
        t == TokenType::And ||
        t == TokenType::Or ||
        t == TokenType::NotEqual ||
        t == TokenType::Identifier
        
    );
}

const Expr nullExpr = {NULLEXPR, ""}; 
const Token trueToken = {TokenType::True, "1"};
const Token falseToken = {TokenType::False, "0"};