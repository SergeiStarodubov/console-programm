#include <stdio.h>
#include <ctype.h>

int main() {
    int tot_chars = 0;
    int tot_lines = 0;
    int tot_words = 0;
    int in_space = 1;
    int c, last = '\n';

    while ((c = getchar()) != EOF) {
        last = c;
        tot_chars++;
        if (isspace(c)) {
            in_space = 1;
            if (c == '\n') {
                tot_lines++;
            } else {
                tot_words += in_space;
                in_space = 0;
            }
        }
        if (last != '\n') {
            tot_lines++;
            printf("Строк, Слов, Символов\n");
            printf(" %3d %3d %3d\n", tot_lines, tot_words, tot_chars);
            return 0;
        }
    }
}