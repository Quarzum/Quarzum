#include <iostream>
#include <fstream>

#include <direct.h>
#include <string>
#include <deque>
#include <experimental/optional>
#include <map>
#include <experimental/any>
#include <cstring>
using namespace std;
using namespace experimental;
/*

    Including utility-type headers

*/
#include "utils/error.hpp"
#include "utils/cli.hpp"
#include "utils/tokentype.h"
#include "utils/tokenlist.hpp"
#include "utils/nodes.h"
#include "utils/ast.hpp"
#include "utils/statement.hpp"
#include "utils/config.h"
#include "utils/variables.hpp"
#include "utils/tokens.hpp"
#include "utils/keywords.hpp"
#include "utils/source.hpp"
#include "utils/utilities.hpp"
#include "utils/configfile.hpp"
/*

    Including compiler core headers

*/

#include "internal/lexer.hpp"
#include "internal/parser.hpp"
#include "internal/linker.hpp"
#include "internal/analyzer.hpp"
#include "internal/generator.hpp"
#include "internal/compile.hpp"