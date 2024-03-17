#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char* getContent(char* path) {
    int len = strlen(path);

    if(strstr(path, ".qz") == NULL){
        fprintf(stderr, "ERROR: File format must be \".qz\"\n");
        exit(1);
    }
    FILE *file;
    char* content;
    size_t size;
    file = fopen(path, "r");
    if(file == NULL){
        fprintf(stderr, "ERROR: File not found\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    content = (char *)malloc(size * sizeof(char));
    if (content == NULL) {
        fprintf(stderr, "ERROR: Memory assignation failed.\n");
        exit(1);
    }

    fread(content, 1, size, file);
    content[size] = 0;
    printf(content);
    fclose(file);
    return content;

}