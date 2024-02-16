#pragma once
#include "./Quarzum.h"
/**
 * Basic component of the Quarzum Modules. Provides some accessories to make the developement cleaner.
*/
class QComponent{
    public:
        /**
         * An integrated ErrorHandler inside every QComponent.
         * Use errorHandler.err() to throw a new error.
         * Use errorHandler.run() at the end of every QComponent main function.
        */
        ErrorHandler errorHandler;
 
    private:
        
};