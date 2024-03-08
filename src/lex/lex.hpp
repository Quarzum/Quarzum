#pragma once
/**
 * File: lex.hpp
 * Description: Contains all the utils used by the lexer and the parser
 * Contents:
 *      - Token
 *      - TokenType
 *      - TokenList
 *      - StringToToken
*/
namespace Quarzum::Lex {
    #include <string>
    #include <vector>
    #include <unordered_map>

    enum TokenType : unsigned char {
        Identifier = 0,
        Integer,
        Number,
        String,
        Char,
        Bool,
        Var,
        Uint,
        Byte,
        Return,
        Function,
        Enum,
        Const,
        Exit,
        Out,
        Input,
        Struct,
        If,
        Else,
        For,
        Foreach,
        In,
        While,
        Do,
        Switch,
        Case,
        Break,
        Continue,
        Repeat,
        Try,
        Catch,
        Finally,
        Throw,
        Module,
        Import,
        Class,
        Public,
        Private,
        Short,
        Long,
        Constuctor,
        Destructor,
        Async,
        Await,
        True,
        False,
        Equal,
        LeftPar,
        RigthPar,
        BitwiseNot,
        BitwiseAnd,
        BitwiseOr,
        BitwiseXor,
        Not,
        And,
        Or,
        Point,
        Comma,
        Plus,
        Minus,
        Product,
        Division,
        Power,
        Remainder,
        IntDivision,
        LeftCurlyBracket,
        RightCurlyBracket,
        LeftSquareBracket,
        RightSquareBracket,
        Semicolon,
        Greater,
        Lower,
        IsEqual,
        GreaterEq,
        LowerEq,
        PlusEq,
        PlusUnary,
        MinusEq,
        MinusUnary,
        ProdEq,
        DivEq,
        RemEq,
        PowEq,
        IntDivEq,
        NotEqual,
        Endl,
        IntegerLit,
        NumberLit,
        StringLit,
        CharLit,
        ByteLit,
        UintLit,
        Error
    };

    struct Token {
        TokenType type;
        std::string value;
    };

    // An object that stores a list of inmutable Tokens.
    class TokenList {

    public:

        void addToken(const Token t){ m_tokens.push_back(t); }

        Token get(const size_t n) const{
            if(n > size()){
                return {};
            }
            return m_tokens.at(n);
        }

        Token operator[](const size_t n){
            return get(n);
        }

        size_t size() const{ return m_tokens.size(); }

        // Creates a TokenList that is a fragment of the original.
        TokenList divide(const size_t from = 0, const size_t to = 1) {
            TokenList result;
            for (size_t i = from; i < to; i++)
            {
                result.addToken(get(i));
            }
            return result;
        }

        std::string toString() {
            std::string result;
            for(Token token : m_tokens) {
                result += token.value + " ";
            }
            return result;
        }

    private:
        std::vector<Token> m_tokens;
    };

    const std::unordered_map<std::string, TokenType> StringToToken = {
        {   "bool",                 Bool              },
        {   "byte",                 Byte              },
        {   "uint",                 Uint              },
        {   "int",                  Integer           },
        {   "number",               Number            },
        {   "char",                 Char              },
        {   "string",               String            },
        {   "var",                  Var               },
        {   "return",               Return            },
        {   "function",             Function          },
        {   "enum",                 Enum              },
        {   "const",                Const             },
        {   "exit",                 Exit              },
        {   "out",                  Out               },
        {   "input",                Input             },
        {   "struct",               Struct            },
        {   "if",                   If                },
        {   "else",                 Else              },
        {   "for",                  For               },
        {   "foreach",              Foreach           },
        {   "in",                   In                },
        {   "while",                While             },
        {   "do",                   Do                },
        {   "switch",               Switch            },
        {   "case",                 Case              },
        {   "break",                Break             },
        {   "continue",             Continue          },
        {   "repeat",               Repeat            },
        {   "try",                  Try               },
        {   "catch",                Catch             },
        {   "finally",              Finally           },
        {   "throw",                Throw             },
        {   "module",               Module            },
        {   "import",               Import            },
        {   "class",                Class             },
        {   "public",               Public            },
        {   "private",              Private           },
        {   "short",                Short             },
        {   "long",                 Long              },
        {   "constructor",          Constuctor        },
        {   "destructor",           Destructor        },
        {   "async",                Async             },
        {   "await",                Await             },
        {   "true",                 True              },
        {   "false",                False             },
        {   "=",                    Equal             },
        {   "(",                    LeftPar           },
        {   ")",                    RigthPar          },
        {   "!!",                   BitwiseNot        },
        {   "&",                    BitwiseAnd        },
        {   "|",                    BitwiseOr         },
        {   "$",                    BitwiseXor        },
        {   "!",                    Not               },
        {   "&&",                   And               },
        {   "||",                   Or                },
        {   ".",                    Point             },
        {   ",",                    Comma             },
        {   "+",                    Plus              },
        {   "-",                    Minus             },
        {   "*",                    Product           },
        {   "/",                    Division          },
        {   "^",                    Power             },
        {   "%",                    Remainder         },
        {   "#/",                   IntDivision       },
        {   "{",                    LeftCurlyBracket  },
        {   "}",                    RightCurlyBracket },
        {   "[",                    LeftSquareBracket },
        {   "]",                    RightSquareBracket},
        {   ";",                    Semicolon         },
        {   ">",                    Greater           },
        {   "<",                    Lower             },
        {   "==",                   IsEqual           },
        {   ">=",                   GreaterEq         },
        {   "<=",                   LowerEq           },
        {   "+=",                   PlusEq            },
        {   "++",                   PlusUnary         },
        {   "-=",                   MinusEq           },
        {   "--",                   MinusUnary        },
        {   "*=",                   ProdEq            },
        {   "/=",                   DivEq             },
        {   "%=",                   RemEq             },
        {   "⁼",                    PowEq             },
        {   "#=",                   IntDivEq          },
        {   "!=",                   NotEqual          }
    };

    unsigned char search(const std::string buff){
        auto it = StringToToken.find(buff);
        if(it != StringToToken.end()){
            return (unsigned char)it->second;
        }
        return 0;
    }
    bool isSymbol(const char c){
        std::string s;
        s = c;
        return search(s) > 0;
    }

    bool isDataType(TokenType t) { 
        return ((unsigned char)(t) >= 1 && (unsigned char)t <= 8); 
    }
    const Token trueToken = {True, "1"};
    const Token falseToken = {False, "0"};
    
} 