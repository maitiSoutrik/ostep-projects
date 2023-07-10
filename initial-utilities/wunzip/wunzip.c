#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    int count;
    char character;

    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    // Loop over all input files
    for(int i = 1; i < argc; i++) {
        file = fopen(argv[i], "rb");  // open the file
        if (file == NULL) {
            printf("wunzip: cannot open file\n");
            exit(1);
        }

        while (fread(&count, sizeof(count), 1, file) && fread(&character, sizeof(char), 1, file)) {
            for (int j = 0; j < count; j++) {
                printf("%c", character);
            }
        }

        fclose(file);  // close the file when it's done
    }

    exit(0);
}
