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
#include "lib/configfile.hpp"
#include "lib/errorcodes.h"
#include "lib/error.hpp"
#include "lib/tokentype.h"
#include "lib/tokenlist.hpp"
#include "lib/utilities.hpp"
/*

    Including compiler core headers

*/

#include "internal/lexer.hpp"
#include "internal/parser.hpp"
#include "internal/linker.hpp"
#include "internal/compile.hpp"