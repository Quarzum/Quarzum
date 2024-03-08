#pragma once
using namespace std;

#include <iostream>
#include <vector>
#include <any>
#include <fstream> 
#include <sstream>
#include <unordered_map>
#include <deque>

namespace Quarzum {
    typedef unsigned char byte;
    typedef unsigned long size;
}

#include "lexer/lex.hpp"

#include "other/errorhandler.cpp"
#include "qcomponent.hpp"

#include "source/source.hpp"
#include "other/utils.cpp"
#include "lexer/lexer.cpp"

#include "other/symboltable.cpp"
#include "parser/node.hpp"
#include "parser/statement.hpp"
#include "parser/parser.cpp"
#include "parser/parseexpr.cpp"
#include "assembler/assembler.cpp"
#include "other/cli.cpp"

