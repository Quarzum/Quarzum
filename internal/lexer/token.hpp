#pragma once
enum TokenType{
    // 0x0 => Keywords
    int_k = 0x001,
    // 0x1 => Special tokens
    id = 0x101,
    // 0x2 => Symbols
    equal = 0x201,
    // 0x3 => Literals
    int_lit = 0x301
};

// A Token is the basic unit of recognition of the lexer
struct Token{
    TokenType type;
    string value;
};