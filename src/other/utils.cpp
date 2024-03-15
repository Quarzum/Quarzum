#pragma once
#include "../Quarzum.h"
/**
 *   Creates a new file and writes content inside it.
 *   @param name The name of the created file.
 *   @param content The content that will be wrote inside the file.
*/
void createFile(const string name,const string content = "") {
    ofstream out(name);
    out << content;
    out.close();
}
// The string array that contains all the Quarzum's keywords and symbols.
const unordered_map<string, TokenType> prefabs = {
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
    {   "case",    TokenType::Case                },
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

const string STDWRITE = "\tmovq $1, %rax\n\tmovq $1, %rdi\n";

bool isSymbol(const char c){
    string s;
    s = c;
    auto it = prefabs.find(s);
    return it != prefabs.end();
}

u_int8_t search(const string buff){
    auto it = prefabs.find(buff);
    if(it != prefabs.end() and (u_int8_t)it->second > 0){
        return (u_int8_t)it->second;
    }
    return 0;
}