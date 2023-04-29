#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse_string(const char* s) {
    if (s == NULL) {
        return NULL;
    }

    int len = strlen(s);
    char* result = (char*)malloc(len + 1);

    for (int i = 0; i < len; i++) {
        result[i] = s[len - i - 1];
    }
    result[len] = '\0';

    return result;
}

int main() {
    char line[81];
    char* reversed;

    while (1) {
        printf("Enter a line of text: ");
        fgets(line, 81, stdin);

        if (strcmp(line, "Done\n") == 0 || strcmp(line, "done\n") == 0 || strcmp(line, "d\n") == 0) {
            break;
        }

        // remove newline character if present
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        reversed = reverse_string(line);
        printf("%s\n", reversed);
        free(reversed);
    }

    return 0;
}
