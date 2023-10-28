#include <iostream>
#include <fstream>
#include <variant>
#include <direct.h>
#include <string>
#include <deque>
#include <optional>
#include <any>
#include <map>
#include <cstring>
using namespace std;
/*

    Including utility-type headers

*/
#include "utils.hpp"

#include "utils/error.hpp"
#include "utils/cli.hpp"

#include "lexer/tokentype.h"
#include "lexer/keywords.hpp"
#include "lexer/tokenlist.hpp"
#include "lexer/tokens.hpp"

#include "parser/expr.h"
#include "parser/nodes.h"

#include "utils/config.h"
#include "utils/variables.hpp"

#include "utils/source.hpp"

#include "utils/configfile.hpp"
/*

    Including compiler core headers

*/

#include "lexer/lexer.hpp"
#include "parser/parser.hpp"
#include "compile.hpp"