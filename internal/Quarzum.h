#include <iostream>
#include <fstream>
#include <variant>
#include <direct.h>
#include <string>
#include <deque>
#include <optional>
#include <map>
#include <any>
using namespace std;
/*

    Including utility-type headers

*/
#include "utils.hpp"
#include "utils/config.h"
#include "utils/error.hpp"
#include "utils/cli.hpp"

#include "lexer/tokentype.h"
#include "lexer/keywords.hpp"
#include "lexer/tokenlist.hpp"

#include "parser/nodes.h"
#include "parser/ast.hpp"

#include "utils/variables.hpp"
#include "utils/source.hpp"
#include "utils/configfile.hpp"
/*

    Including compiler core headers

*/
#include "lexer/lexer.cpp"
#include "parser/parser.cpp"
#include "analyzer/analyzer.cpp"
#include "generator/generator.cpp"
#include "compile.hpp"