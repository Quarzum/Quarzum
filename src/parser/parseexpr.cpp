#pragma once
#include "../Quarzum.h"
#define divideNodes a = parseExpr(list.divide(0,i)); b = parseExpr(list.divide(i+1,list.size()));

exprType typeToExpr(TokenType t){
    const unordered_map<TokenType, exprType> types = {
        {TokenType::IntegerLit,INT},
        {TokenType::StringLit,STRING},
        {TokenType::True, BOOL},
        {TokenType::False, BOOL},
        {TokenType::ByteLit, BYTE},
        {TokenType::CharLit, CHAR},
        {TokenType::UintLit, UINT},
        {TokenType::NumberLit, NUMBER}
    };
    auto it = types.find(t);
    return it->second;
}
exprType strToExpr(string t){
    const unordered_map<string, exprType> types = {
        {"int",INT},
        {"string",STRING},
        {"bool", BOOL},
        {"byte", BYTE},
        {"char", CHAR},
        {"uint", UINT},
        {"number", NUMBER}
    };
    auto it = types.find(t);
    return it->second;
}
bool Parser::matchTypes(exprType e, TokenType t) {
    if(t == TokenType::Var) return true;
    return (u_int8_t)exprType(e) == (u_int8_t)TokenType(t);
}

exprType sumTypes (exprType a, exprType b) {
    cout << a << b << '\n';
    if(a < 7 && b < 7){return a > b? (a==CHAR? b : a) : a;}
    if((a == 7 && b > 5) || (b == 7 && a > 5)){ return STRING;}
    if(a == 6 && b == 6){ return CHAR;}
    return NULLEXPR;
}

Expr Parser::parseExpr(TokenList list) {
    if(list.size() == 1) {
        if(list[0].type == TokenType::Identifier) {
            if(symbolTable.find(list[0].value).name == ""){
                
                return nullExpr;
            }
            return Expr {
                .type = strToExpr(symbolTable.find(list[0].value).type),
                .value = symbolTable.find(list[0].value).value
            };
        }
        return Expr {
            .type = typeToExpr(list[0].type),
            .value = list[0].value
        };
    }
    u_int8_t ident = 0;
    Expr a = nullExpr;
    Expr b = nullExpr;
    exprType typeBlend;
    for (size_t i = 0; i < list.size(); ++i)
    {   
        switch (list[i].type)
        {
        case TokenType::Or:
            divideNodes;
            return Expr{
                .type = BOOL,
                .value = a.value + list[i].value + b.value
            };
        case TokenType::And:
            divideNodes;
            return Expr{
                .type = BOOL,
                .value = a.value + list[i].value + b.value
            };
        case TokenType::BitwiseOr:
            divideNodes;
            return Expr{
                .type = BOOL,
                .value = a.value + list[i].value + b.value
            };
        case TokenType::BitwiseXor:
            divideNodes;
            return Expr{
                .type = BOOL,
                .value = a.value + list[i].value + b.value
            };         
        case TokenType::BitwiseAnd:
            divideNodes;
            return Expr{
                .type = BOOL,
                .value = a.value + list[i].value + b.value
            };
        case TokenType::Greater:
        case TokenType::GreaterEq:
        case TokenType::Lower:
        case TokenType::LowerEq:
            divideNodes;
            return Expr{
                .type = BOOL,
                .value = a.value + list[i].value + b.value
            };
        case TokenType::IsEqual:
        case TokenType::NotEqual:
            divideNodes;
            return Expr{
                .type = BOOL,
                .value = a.value + list[i].value + b.value
            };
        case TokenType::Plus:
        case TokenType::Minus:
            divideNodes;
            typeBlend = sumTypes(a.type, b.type);
            if(typeBlend == NULLEXPR) {
                
                return nullExpr;
            }
            return Expr{
                .type = typeBlend,
                .value = a.value + list[i].value + b.value
            };
        case TokenType::Product:
        case TokenType::Division:
        case TokenType::Remainder:
        case TokenType::Power:
            divideNodes;
            return Expr{
                .type = INT,
                .value = a.value + list[i].value + b.value
            };

        default: break;
        }
    }
    
   
    return nullExpr;   
}