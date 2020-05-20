#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[]) {

    char* cur_file_path = argv[1];
    char* new_file_path = argv[2];
    if (cur_file_path == NULL || new_file_path == NULL) {
        puts("No enough arguments. Must be 2");
        exit(1);
    }
    if (argc > 3) {
        puts("Too match arguments");
        exit(1);
    }

    FILE *cur_file = fopen( cur_file_path, "r" );
    FILE *new_file = fopen( new_file_path, "w" );

    fseek(cur_file, 0L, SEEK_END);
    long sz = ftell(cur_file);
    char* buffer = (char*) malloc(sz);

    assert (cur_file_path != NULL);
    assert(new_file_path != NULL);

    while (fread(buffer, sizeof(char), sz , cur_file) > 0 )
    {
        fwrite(buffer, sizeof(char), sz, new_file);
    }
    free(buffer);
    fclose(cur_file);
    fclose(new_file);
    return 0;
}


