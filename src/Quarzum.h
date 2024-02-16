#pragma once
using namespace std;

const bool DEBUGMODE = false;

#include <string>
#include <iostream>
#include <deque>
#include <any>
#include <fstream> 
#include <sstream>
#include <variant>
#include <map>
#include <unordered_map>

#include "other/errorhandler.cpp"
#include "qcomponent.hpp"
#include "lexer/token.hpp"

#include "source/source.hpp"
#include "other/utils.cpp"
#include "other/variables.cpp"
#include "lexer/lexer.cpp"

#include "parser/node.hpp"
#include "parser/statement.hpp"
#include "parser/parser.cpp"

#include "assembler/assembler.cpp"

#include "other/cli.cpp"

