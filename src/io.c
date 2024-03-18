/**
 * Reads a file and returns its content. If the file does not
 * exist or the file extension is not ".qz", the program stops.
 * @param path The file path
*/
const char* getContent(const char* path) {

    int len = strlen(path);

    if(path[len - 3] != '.' || path[len - 2] != 'q' || path[len - 1] != 'z'){
        err("File format must be \".qz\"");
    }
    FILE *file;
    char* content;

    file = fopen(path, "r");
    if(file == NULL){
        err("File not found");
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    content = (char *)malloc(size * sizeof(char));
    if (content == NULL) {
        fprintf(stderr, "ERROR: Memory assignation failed.\n");
        exit(1);
    }

    fread(content, 1, size, file);
    content[size] = '\0';
    printf(content);
    fclose(file);
    return content;

}
/**
 * Creates a file with a name and a content. Generally used to create
 * the assembly code into a separate file.
 * @param name The file name
 * @param content The file content
*/
void createFile(const char* name, const char* content = "") {
    FILE *file;
    file = fopen(name, "w+");
    fprintf(file, content);
    fclose(file);
}