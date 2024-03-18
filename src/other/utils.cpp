#pragma once
#include "../Quarzum.h"

// The string array that contains all the Quarzum's keywords and symbols.
const unordered_map<string, TokenType> prefabs = {
    {   "bool",    Bool              },
    {   "byte",    Byte              },
    {   "uint",    Uint              },
    {   "int",     Integer           },
    {   "number",  Number            },
    {   "char",    Char              },
    {   "string",  String            },
    {   "var",     Var               },
    {   "return",  Return            },
    {   "function",Function          },
    {   "enum",    Enum              },
    {   "const",   Const             },
    {   "exit",    Exit              },
    {   "out",     Out               },
    {   "input",   Input             },
    {   "struct",  Struct            },
    {   "if",      If                },
    {   "else",    Else              },
    {   "for",     For               },
    {   "foreach", Foreach           },
    {   "in",      In                },
    {   "while",   While             },
    {   "do",      Do                },
    {   "switch",  Switch            },
    {   "case",    Case                },
    {   "break",   Break             },
    {   "continue",Continue          },
    {   "repeat",  Repeat            },
    {   "try",     Try               },
    {   "catch",   Catch             },
    {   "finally", Finally           },
    {   "throw",   Throw             },
    {   "module",  Module            },
    {   "import",  Import            },
    {   "class",   Class             },
    {   "public",  Public            },
    {   "private", Private           },
    {   "short",   Short             },
    {   "long",    Long              },
    {   "constructor",Constuctor     },
    {   "destructor",Destructor      },
    {   "async",   Async             },
    {   "await",   Await             },
    {   "true",    True              },
    {   "false",   False             },
    {   "=",       Equal             },
    {   "(",       LeftPar           },
    {   ")",       RigthPar          },
    {   "!!",      BitwiseNot        },
    {   "&",       BitwiseAnd        },
    {   "|",       BitwiseOr         },
    {   "$",       BitwiseXor        },
    {   "!",       Not               },
    {   "&&",      And               },
    {   "||",      Or                },
    {   ".",       Point             },
    {   ",",       Comma             },
    {   "+",       Plus              },
    {   "-",       Minus             },
    {   "*",       Product           },
    {   "/",       Division          },
    {   "^",       Power             },
    {   "%",       Remainder         },
    {   "#/",      IntDivision       },
    {   "{",       LeftCurlyBracket  },
    {   "}",       RightCurlyBracket },
    {   "[",       LeftSquareBracket },
    {   "]",       RightSquareBracket},
    {   ";",       Semicolon         },
    {   ">",       Greater           },
    {   "<",       Lower             },
    {   "==",      IsEqual           },
    {   ">=",      GreaterEq         },
    {   "<=",      LowerEq           },
    {   "+=",      PlusEq            },
    {   "++",      PlusUnary         },
    {   "-=",      MinusEq           },
    {   "--",      MinusUnary        },
    {   "*=",      ProdEq            },
    {   "/=",      DivEq             },
    {   "%=",      RemEq             },
    {   "⁼",       PowEq             },
    {   "#=",      IntDivEq          },
    {   "!=",      NotEqual          }
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