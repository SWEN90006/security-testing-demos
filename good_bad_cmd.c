#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 4

void good_bad(char buf[BUF_SIZE]) {
    if (buf[0] == 'b') {
        if (buf[1] == 'a') {
            if (buf[2] == 'd') {
                if (buf[3] == '!') {
                    abort();
                }
            }
        }
    }
}

int main(void) {
    char *buffer;
    char input[64]; // generous input buffer for scanf

    printf("Enter a string (try \"bad!\"): ");
    if (scanf("%63s", input) != 1) {
        printf("Error reading input.\n");
        exit(1);
    }

    if (strlen(input) < BUF_SIZE) {
        printf("Error! Input is too short (need at least %d characters).\n", BUF_SIZE);
        exit(1);
    }

    buffer = (char *)malloc(BUF_SIZE);
    if (buffer == NULL) {
        printf("Error! Memory allocation failed.\n");
        exit(1);
    }

    memcpy(buffer, input, BUF_SIZE);
    good_bad(buffer);

    printf("No crash triggered. Buffer: %.4s\n", buffer);

    free(buffer);
    return 0;
}
