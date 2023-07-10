#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    int current_char;
    int last_char = EOF;
    int count = 0;

    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    // Loop over all input files
    for(int i = 1; i < argc; i++) {
        file = fopen(argv[i], "r");  // open the file
        if (file == NULL) {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        while ((current_char = fgetc(file)) != EOF) {
            if (last_char == current_char) {
                count++;
            } else {
                if (last_char != EOF) {
                    fwrite(&count, sizeof(count), 1, stdout);
                    fwrite(&last_char, sizeof(char), 1, stdout);
                }
                count = 1;
                last_char = current_char;
            }
        }

        fclose(file);  // close the file when it's done
    }

    // Write the final count and character to stdout
    if (count > 0 && last_char != EOF) {
        fwrite(&count, sizeof(count), 1, stdout);
        fwrite(&last_char, sizeof(char), 1, stdout);
    }

    exit(0);
}
