#pragma once
enum TokenType{
    // 0x0 => Keywords
    int_k       = 0x001,
    num_k       = 0x002,
    str_k       = 0x003,
    char_k      = 0x004,
    bool_k      = 0x005,
    any_k       = 0x006,
    return_k    = 0x007,
    function_k  = 0x008,
    enum_k      = 0x009,
    const_k     = 0x00a,
    exit_k      = 0x00b,
    out_k       = 0x00c,
    // 0x1 => Special tokens
    id          = 0x101,
    // 0x2 => Symbols
    equal       = 0x201,
    left_par    = 0x202,
    rigth_par   = 0x203,
    // 0x3 => Literals
    int_lit     = 0x301,
    num_lit     = 0x302,
    str_lit     = 0x303,
    bool_lit    = 0x304,
    char_lit    = 0x305
};

// A Token is the basic unit of recognition of the lexer
struct Token{
    TokenType type;
    string value;
};