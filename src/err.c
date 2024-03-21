#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KYEL  "\x1B[33m"

/**
 * Throws a fatal error and stops the program, showing in the
 * console the description of the error.
 * @param description The error description
*/
void err(const char* description) {
    fprintf(stderr,KRED "Error" KNRM ": %s\n", description);
    exit(1);
}

/**
 * Throws a warning and the program continues, showing in the
 * console the description of the error.
 * @param description The warning description
*/
void warn(const char* description) {
    fprintf(stderr,KYEL "Warning" KNRM ": %s\n", description);
}