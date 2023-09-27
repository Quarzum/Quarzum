#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <experimental/optional>
#include <stdio.h>
#include <time.h>
#include <map>
using namespace std;
/*

    Including utility-type headers

*/

#include "utils/errorcodes.h"
#include "utils/error.hpp"
#include "utils/tokentype.h"
#include "utils/tokenlist.hpp"
#include "utils/utilities.hpp"
#include "utils/config.h"
#include "utils/configfile.hpp"
/*

    Including compiler core headers

*/

#include "internal/lexer.hpp"
#include "internal/parser.hpp"
#include "internal/linker.hpp"
#include "internal/compile.hpp"