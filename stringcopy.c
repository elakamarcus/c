#include <stdio.h>

void strcape (char *a, char *b) {
        printf("Calling string copy function...:\n");
        while ((*a++ = *b++) != '\0');
}

int main() {

        char first[30] = "Hello.";
        char scnd[30] = "What about now.";
        printf("First string: %s\n", first);
        printf("Second string: %s \n", scnd);

        char *a = first;
        char *b = scnd;

        strcape(b, a);

        printf("First:: %s\n", first);
        printf("Second: %s\n", scnd);

        return 0;
}
