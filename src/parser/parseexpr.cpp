#pragma once
#include "../Quarzum.h"
#define divideNodes a = parseExpr(list.divide(0,n)); b = parseExpr(list.divide(n+1,list.size()));

exprType typeToExpr(TokenType t){
    const unordered_map<TokenType, exprType> types = {
        {int_lit,INT},
        {str_lit,STRING},
        {true_k, BOOL},
        {false_k, BOOL},
        {byte_lit, BYTE},
        {char_lit, CHAR},
        {uint_lit, UINT},
        {num_lit, NUMBER}
    };
    auto it = types.find(t);
    return it->second;
}

bool Parser::matchTypes(exprType e, TokenType t) {
    if(t == var_k) return true;
    return exprType(e) == TokenType(t);
}

Expr Parser::parseExpr(TokenList list) {

    if(list.size() == 1) {
        return Expr {
            .type = typeToExpr(list[0].type),
            .value = list[0]
        };
    }
    Expr a = nullExpr;
    Expr b = nullExpr;
    // Operator Precedence Level 7 (||)
    for (size_t n = 0; n < list.size(); ++n)
    {
        if(list[n].type == TokenType::or_s){
            divideNodes;
            return Expr {
                .type = exprType::BOOL,
                .value = (a.value.value == "1") || (b.value.value == "1") ? trueToken : falseToken
            };
        }
    }  
    // Operator Precedence Level 6 (&&)
    for (size_t n = 0; n < list.size(); ++n)
    {
        if(list[n].type == TokenType::and_s){
            divideNodes;
            return Expr {
                .type = exprType::BOOL,
                .value = (a.value.value == "1") && (b.value.value == "1") ? trueToken : falseToken
            };
        }
    }  
    // Operator Precedence Level 5 (>, >=, <, <=)
    for (size_t n = 0; n < list.size(); ++n)
    {
        switch (list[n].type)
        {
        case TokenType::greater_eq:
            divideNodes;
            return Expr {
                .type = exprType::BOOL,
                .value = stoi(a.value.value) >= stoi(b.value.value)? trueToken : falseToken
            };
        case TokenType::greater:
            divideNodes;
            return Expr {
                .type = exprType::BOOL,
                .value = stoi(a.value.value) > stoi(b.value.value)? trueToken : falseToken
            };
        case TokenType::less_eq:
            divideNodes;
            return Expr {
                .type = exprType::BOOL,
                .value = stoi(a.value.value) <= stoi(b.value.value)? trueToken : falseToken
            };
        case TokenType::less:
            divideNodes;
            return Expr {
                .type = exprType::BOOL,
                .value = stoi(a.value.value) < stoi(b.value.value)? trueToken : falseToken
            };
        default: continue;
        }
    } 
    // Operator Precedence Level 4 (==, !=)
    for (size_t n = 0; n < list.size(); ++n)
    {
        switch (list[n].type)
        {
        case TokenType::is_equal:
            divideNodes;
            return Expr {
                .type = exprType::BOOL,
                .value = stoi(a.value.value) == stoi(b.value.value)? trueToken : falseToken
            };
        case TokenType::not_equal:
            divideNodes;
            return Expr {
                .type = exprType::BOOL,
                .value = stoi(a.value.value) != stoi(b.value.value)? trueToken : falseToken
            };
        default: continue;
        }
    } 
    
    // Operator Precedence Level 1 (*, /, %)

    // Operator Precedence Level 0 (+, -)
    for (size_t n = 0; n < list.size(); ++n)
    {
        if (list[n].type == TokenType::plus)
        {
            divideNodes;
            return Expr {
                .type = exprType::INT,
                .value = Token{ int_lit , to_string(stoi(a.value.value) + stoi(b.value.value)) }
            };
        };
        if (list[n].type == TokenType::minus)
        {
            divideNodes;
            return Expr {
                .type = exprType::INT,
                .value = Token{ int_lit , to_string(stoi(a.value.value) - stoi(b.value.value)) }
            };
        };
    }

    

}