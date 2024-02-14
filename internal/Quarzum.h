#pragma once
using namespace std;

#include <string>
#include <iostream>
#include <deque>
#include <any>
#include <fstream> 
#include <sstream>
#include <variant>
#include <map>

#include "lexer/token.hpp"
#include "other/errorhandler.cpp"
#include "other/utils.cpp"
#include "other/variables.cpp"
#include "lexer/lexer.cpp"

#include "parser/statement.hpp"
#include "parser/parser.cpp"

#include "assembler/assembler.cpp"

#include "other/cli.cpp"