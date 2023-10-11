const map<string, __int8> keywords = {
    {"exit", 0},
    {"return", 1},
    {"import", 2},
    {"from", 3},
    {"int", 5},
    {"string", 7},
    {"num", 9},
    {"true", 10},
    {"false", 11},
    {"bool", 13},
    {"any", 15},
    {"function", 16},
    {"null", 17},
    {"struct", 18},
    {"enum", 19},
    {"class", 20},
    {"public", 21},
    {"private", 22},
    {"module", 23},
    {"and", 25},
    {"or", 26},
    {"not", 27},
    {"const", 39},
    {"unsigned", 40},
    {"short", 41},
    {"long", 42},
    {"this", 48},
    {"static", 49},
    {"delete", 50},
    {"out", 54},
    {"input", 56},
    {"typeOf", 56},
};
const __int8 findKeyword(string keyword) { return keywords.at(keyword); }
const bool isKeyword(string src) { return keywords.count(src); }