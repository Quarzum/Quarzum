#pragma once
#include "../Quarzum.h"
#define divideNodes a = parseExpr(list.divide(0,i)); b = parseExpr(list.divide(i+1,list.size()));

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
    if(t == var_k) return true;
    return exprType(e) == TokenType(t);
}

exprType sumTypes (exprType a, exprType b) {
    if( (a == NUMBER && b != STRING) || (b == NUMBER && a != STRING))   { return NUMBER;}
    if( (a == INT && b != STRING) || (b == INT && a != STRING))   { return INT;   }
    if( (a == UINT && b != STRING) || (b == UINT && a != STRING)) { return UINT;  }
    if( a == CHAR || b == CHAR ) { return CHAR;  }
    if( (a == BYTE && b != STRING ) || (b == BYTE && a != STRING)) { return BYTE;  }
    if( (a == STRING && b == STRING) || b == CHAR) {return STRING;}
    return NULLEXPR;
}

Expr Parser::parseExpr(TokenList list) {
    if(list.size() == 1) {
        if(list[0].type == id) {
            if(symbolTable.find(list[0].value).name == ""){
                errorHandler.err({syntax_err,m_line,"Undefined reference to " + list[0].value});
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
        case or_s:
            divideNodes;
            return Expr{
                .type = BOOL,
                .value = a.value + list[i].value + b.value
            };
        case and_s:
            divideNodes;
            return Expr{
                .type = BOOL,
                .value = a.value + list[i].value + b.value
            };
        case or_bit:
            divideNodes;
            return Expr{
                .type = BOOL,
                .value = a.value + list[i].value + b.value
            };
        case xor_bit:
            divideNodes;
            return Expr{
                .type = BOOL,
                .value = a.value + list[i].value + b.value
            };         
        case and_bit:
            divideNodes;
            return Expr{
                .type = BOOL,
                .value = a.value + list[i].value + b.value
            };
        case TokenType::greater:
        case greater_eq:
        case TokenType::less:
        case less_eq:
            divideNodes;
            return Expr{
                .type = BOOL,
                .value = a.value + list[i].value + b.value
            };
        case is_equal:
        case not_equal:
            divideNodes;
            return Expr{
                .type = BOOL,
                .value = a.value + list[i].value + b.value
            };
        case TokenType::plus:
        case TokenType::minus:
            divideNodes;
            typeBlend = sumTypes(a.type, b.type);
            if(typeBlend == NULLEXPR) {
                errorHandler.err({syntax_err, m_line, "Invalid operands for '"+list[i].value+"' operation"});
                return nullExpr;
            }
            return Expr{
                .type = typeBlend,
                .value = a.value + list[i].value + b.value
            };
        case prod:
        case division:
        case remainder:
        case power:
            divideNodes;
            return Expr{
                .type = INT,
                .value = a.value + list[i].value + b.value
            };

        default: break;
        }
    }
    
    errorHandler.err({syntax_err, m_line, "Invalid expression"});
    return nullExpr;   
}