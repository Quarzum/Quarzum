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
#include <regex>
using namespace std;
/*

    Including utility-type headers

*/
#include "utils/error.hpp"
#include "utils/cli.hpp"

#include "lexer/tokentype.h"
#include "lexer/tokenlist.hpp"
#include "lexer/tokens.hpp"

#include "utils/config.h"
#include "utils/variables.hpp"

#include "utils/source.hpp"

#include "utils/configfile.hpp"
/*

    Including compiler core headers

*/

#include "lexer/lexer.hpp"

#include "internal/compile.hpp"