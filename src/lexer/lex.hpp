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

    enum class TokenType : byte {
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
        {   "bool",    TokenType::Bool              },
        {   "byte",    TokenType::Byte              },
        {   "uint",    TokenType::Uint              },
        {   "int",     TokenType::Integer           },
        {   "number",  TokenType::Number            },
        {   "char",    TokenType::Char              },
        {   "string",  TokenType::String            },
        {   "var",     TokenType::Var               },
        {   "return",  TokenType::Return            },
        {   "function",TokenType::Function          },
        {   "enum",    TokenType::Enum              },
        {   "const",   TokenType::Const             },
        {   "exit",    TokenType::Exit              },
        {   "out",     TokenType::Out               },
        {   "input",   TokenType::Input             },
        {   "struct",  TokenType::Struct            },
        {   "if",      TokenType::If                },
        {   "else",    TokenType::Else              },
        {   "for",     TokenType::For               },
        {   "foreach", TokenType::Foreach           },
        {   "in",      TokenType::In                },
        {   "while",   TokenType::While             },
        {   "do",      TokenType::Do                },
        {   "switch",  TokenType::Switch            },
        {   "case",    TokenType::Case              },
        {   "break",   TokenType::Break             },
        {   "continue",TokenType::Continue          },
        {   "repeat",  TokenType::Repeat            },
        {   "try",     TokenType::Try               },
        {   "catch",   TokenType::Catch             },
        {   "finally", TokenType::Finally           },
        {   "throw",   TokenType::Throw             },
        {   "module",  TokenType::Module            },
        {   "import",  TokenType::Import            },
        {   "class",   TokenType::Class             },
        {   "public",  TokenType::Public            },
        {   "private", TokenType::Private           },
        {   "short",   TokenType::Short             },
        {   "long",    TokenType::Long              },
        {   "constructor",TokenType::Constuctor     },
        {   "destructor",TokenType::Destructor      },
        {   "async",   TokenType::Async             },
        {   "await",   TokenType::Await             },
        {   "true",    TokenType::True              },
        {   "false",   TokenType::False             },
        {   "=",       TokenType::Equal             },
        {   "(",       TokenType::LeftPar           },
        {   ")",       TokenType::RigthPar          },
        {   "!!",      TokenType::BitwiseNot        },
        {   "&",       TokenType::BitwiseAnd        },
        {   "|",       TokenType::BitwiseOr         },
        {   "$",       TokenType::BitwiseXor        },
        {   "!",       TokenType::Not               },
        {   "&&",      TokenType::And               },
        {   "||",      TokenType::Or                },
        {   ".",       TokenType::Point             },
        {   ",",       TokenType::Comma             },
        {   "+",       TokenType::Plus              },
        {   "-",       TokenType::Minus             },
        {   "*",       TokenType::Product           },
        {   "/",       TokenType::Division          },
        {   "^",       TokenType::Power             },
        {   "%",       TokenType::Remainder         },
        {   "#/",      TokenType::IntDivision       },
        {   "{",       TokenType::LeftCurlyBracket  },
        {   "}",       TokenType::RightCurlyBracket },
        {   "[",       TokenType::LeftSquareBracket },
        {   "]",       TokenType::RightSquareBracket},
        {   ";",       TokenType::Semicolon         },
        {   ">",       TokenType::Greater           },
        {   "<",       TokenType::Lower             },
        {   "==",      TokenType::IsEqual           },
        {   ">=",      TokenType::GreaterEq         },
        {   "<=",      TokenType::LowerEq           },
        {   "+=",      TokenType::PlusEq            },
        {   "++",      TokenType::PlusUnary         },
        {   "-=",      TokenType::MinusEq           },
        {   "--",      TokenType::MinusUnary        },
        {   "*=",      TokenType::ProdEq            },
        {   "/=",      TokenType::DivEq             },
        {   "%=",      TokenType::RemEq             },
        {   "⁼",       TokenType::PowEq             },
        {   "#=",      TokenType::IntDivEq          },
        {   "!=",      TokenType::NotEqual          }
    };

    byte search(const std::string buff){
        auto it = StringToToken.find(buff);
        if(it != StringToToken.end()){
            return (byte)it->second;
        }
        return 0;
    }
    bool isSymbol(const char c){
        std::string s;
        s = c;
        return search(s) > 0;
    }

    bool isDataType(TokenType t) { 
        return ((byte)(t) >= 1 && (byte)t <= 8); 
    }
    const Token trueToken = {TokenType::True, "1"};
    const Token falseToken = {TokenType::False, "0"};
    
} 