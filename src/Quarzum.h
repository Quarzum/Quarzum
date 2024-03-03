#pragma once
using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <any>
#include <fstream> 
#include <sstream>
#include <unordered_map>

#include "other/errorhandler.cpp"
#include "qcomponent.hpp"
#include "lexer/token.hpp"
#include "lexer/tokenlist.hpp"

#include "source/source.hpp"
#include "other/utils.cpp"
#include "lexer/lexer.cpp"

#include "other/symboltable.cpp"
#include "parser/node.hpp"
#include "parser/statement.hpp"
#include "parser/parser.cpp"
#include "assembler/assembler.cpp"
#include "other/cli.cpp"

