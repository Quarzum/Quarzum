Collection keywords = Collection({

    {"int", INT_K},
    {"num", NUM_K},
    {"string", STR_K},
    {"char", CHAR_K},
    {"bool", BOOL_K},
    {"any", ANY_K},
    {"null", NULL_K},
    {"function", FUNCTION_K},
    {"return", RETURN},
    {"exit", EXIT},
    {"if", IF},
    {"else", ELSE},
    {"for", FOR},
    {"while", WHILE},
    {"switch", SWITCH},
    {"case", CASE},
    {"break", BREAK},
    {"continue", CONTINUE},
    {"default", DEFAULT},
    {"import", IMPORT},
    {"from", FROM},
    {"module", MODULE},
    {"and", AND},
    {"or", OR},
    {"not", NOT},
    {"class", CLASS},
    {"public", PUBLIC},
    {"private", PRIVATE},
    {"construct", INIT},
    {"destroy", DESTROY},
    {"struct", STRUCT},
    {"enum", ENUM},
    {"try", TRY},
    {"catch", CATCH},
    {"finally", FINALLY},
    {"const", CONST},
    {"static", STATIC},
    {"typeof", TYPEOF},
    {"throw", THROW},
    {"delete", DELETE},
    {"true", BOOL},
    {"false", BOOL},
    {"out", OUT},
    {"input", INPUT}

});

Collection symbols = Collection({

    {"=", EQUAL},
    {"+", PLUS},
    {"-", MINUS},
    {"*", PRODUCT},
    {"/", DIVIDE},
    {"^", POWER},
    {"%", INTDIV},
    {"(", PAR_OPEN},
    {")", PAR_CLOSE},
    {"[", SQUARE_OPEN},
    {"]", SQUARE_CLOSE},
    {"{", CURLY_OPEN},
    {"}", CURLY_CLOSE},
    {"&", AND},
    {"|", OR},
    {"!", NOT},
    {">", GREATER},
    {"<", LESS}

});

Collection composedSymbols = Collection({

    {"==", IS_EQUAL},
    {">=", GREATER_EQUAL},
    {"<=", LESS_EQUAL},
    {"+=", PLUS_EQUAL},
    {"-=", MINUS_EQUAL},
    {"*=", PROD_EQUAL},
    {"/=", DIVIDE_EQUAL},
    {"^=", POWER_EQUAL},
    {"%=", INTDIV_EQUAL},
    {"++", UNARY_PLUS},
    {"--", UNARY_MINUS}

});