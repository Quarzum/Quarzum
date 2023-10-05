#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <deque>
#include <experimental/optional>
#include <stdio.h>
#include <time.h>
#include <map>
#include <experimental/any>
#include <vector>
using namespace std;
using namespace experimental;
/*

    Including utility-type headers

*/

#include "utils/errorcodes.h"
#include "utils/error.hpp"
#include "utils/tokentype.h"
#include "utils/tokenlist.hpp"
#include "utils/nodes.h"
#include "utils/statement.hpp"
#include "utils/config.h"
#include "utils/utilities.hpp"
#include "utils/configfile.hpp"
/*

    Including compiler core headers

*/

#include "internal/lexer.hpp"
#include "internal/parser.hpp"
#include "internal/linker.hpp"
#include "internal/generator.hpp"
#include "internal/compile.hpp"