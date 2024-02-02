#pragma once
#include "../Quarzum.h"

enum StmtType{
    return_stmt
};

// A Statement is a structure that contains one order of type "type" and with 8 possible arguments to pass in.
struct Statement{
    StmtType type;
    any args[8];
};