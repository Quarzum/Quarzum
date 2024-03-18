#pragma once
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <any>
#include <fstream> 
#include <sstream>
#include <unordered_map>
#include <deque>

#include "other/errorhandler.cpp"
#include "qcomponent.hpp"
#include "lexer/token.hpp"
#include "lexer/tokenlist.hpp"

#include "err.c"
#include "io.c"
#include "other/utils.cpp"
#include "lexer/lexer.cpp"

#include "other/symboltable.cpp"
#include "parser/node.hpp"
#include "parser/statement.hpp"
#include "parser/parser.cpp"
#include "parser/parseexpr.cpp"
#include "assembler/assembler.cpp"

