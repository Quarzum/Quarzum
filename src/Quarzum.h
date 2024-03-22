#pragma once
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <any>
#include <sstream>
#include <unordered_map>
#include <deque>


#include "./include/token.h"
#include "./include/err.h"
#include "./include/io.h"

#include "lexer/tokenlist.hpp"

#include "lex.c"

#include "other/symboltable.cpp"
#include "parser/node.hpp"
#include "parser/statement.hpp"
#include "parser/parser.cpp"
#include "parser/parseexpr.cpp"
#include "assembler/assembler.cpp"

