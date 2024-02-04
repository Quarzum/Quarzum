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
    input_k     = 0x00d,
    struct_k    = 0x00e,
    if_k        = 0x00f,
    else_k      = 0x010,
    for_k       = 0x011,
    foreach_k   = 0x012,
    while_k     = 0x013,
    do_k        = 0x014,
    break_k     = 0x015,
    continue_k  = 0x016,
    repeat_k    = 0x017,
    try_k       = 0x018,
    catch_k     = 0x019,
    finally_k   = 0x01a,
    throw_k     = 0x01b,
    module_k    = 0x01c,
    import_k    = 0x01d,
    class_k     = 0x01e,
    public_k    = 0x01f,
    private_k   = 0x020,
    uint_k      = 0x021,
    short_k     = 0x022,
    long_k      = 0x023,
    byte_k      = 0x024,
    // 0x1 => Special tokens
    id          = 0x000,
    // 0x2 => Symbols
    eq          = 0x201,
    left_par    = 0x202,
    rigth_par   = 0x203,
    not_bit     = 0x204,
    and_bit     = 0x205,
    or_bit      = 0x206,
    xor_bit     = 0x207,
    not_s       = 0x208,
    and_s       = 0x209,
    or_s        = 0x20a,
    xor_s       = 0x20b,
    point       = 0x20c,
    comma       = 0x20d,
    plus        = 0x20e,
    minus       = 0x20f,
    prod        = 0x210,
    division    = 0x211,
    power       = 0x212,
    left_cb     = 0x213,
    rigth_cb    = 0x214,
    left_sb     = 0x215,
    rigth_sb    = 0x216,
    semicolon   = 0x217,
    greater     = 0x218,
    less        = 0x219,
    is_equal    = 0x21a,
    greater_eq  = 0x21b,
    less_eq     = 0x21c,
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