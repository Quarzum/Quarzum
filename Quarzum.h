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
#include "utils/error.hpp"
#include "utils/cli.hpp"
#include "utils/tokentype.h"
#include "utils/tokenlist.hpp"
#include "utils/nodes.h"
#include "utils/config.h"
#include "utils/variables.hpp"
#include "utils/tokens.hpp"
#include "utils/keywords.hpp"
#include "utils/source.hpp"
#include "utils/utilities.hpp"
#include "utils/ast.hpp"
#include "utils/configfile.hpp"
/*

    Including compiler core headers

*/

#include "internal/lexer.hpp"
#include "internal/parser.hpp"
#include "internal/linker.hpp"
#include "internal/generator.hpp"
#include "internal/compile.hpp"