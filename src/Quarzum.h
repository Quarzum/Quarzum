#pragma once
using namespace std;


const bool DEBUGMODE = false;

#include <string>
#include <iostream>
#include <vector>
#include <any>
#include <fstream> 
#include <sstream>
#include <variant>
#include <unordered_map>
#include <chrono>

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

