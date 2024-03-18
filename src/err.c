/**
 * Throws a fatal error and stops the program, showing in the
 * console the description of the error.
 * @param description The error description
*/
void err(const char* description) {
    fprintf(stderr, "Error: %s ", description);
    exit(1);
}