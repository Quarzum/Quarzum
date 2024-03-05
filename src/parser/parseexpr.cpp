#pragma once
#include "../Quarzum.h"

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

Expr Parser::parseExpr(TokenList list) {

    if(list.size() == 1) {
        cout << list[0].value;
        return Expr {
            .type = typeToExpr(list[0].type),
            .value = list[0]
        };
    }

    // Operator Precedence Level 0 
    // for (size_t n = 0; n < list.size(); ++n)
    // {
    //     if (list[n].type == TokenType::plus)
    //     {
    //         divideNodes;
    //         return Expr {
    //             .type = exprType::INT,
    //             .value = Token{ int_lit , to_string(stoi(a.value.value) + stoi(b.value.value)) }
    //         };
    //     };
    //     if (list[n].type == TokenType::minus)
    //     {
    //         divideNodes;
    //         return Expr {
    //             .type = exprType::INT,
    //             .value = Token{ int_lit , to_string(stoi(a.value.value) - stoi(b.value.value)) }
    //         };
    //     };
    // }

}