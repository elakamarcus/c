#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

/* getline custom implementation */
int getlina(char *s, int max){
    if(fgets(s, max, stdin)== NULL)
        return 0;
    else {
        return strlen(s);
    }
}

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[]){
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0; 

    while (--argc > 0 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal operation %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
    if(argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while(getlina(line, MAXLINE) > 0) {
            lineno++;
            if((strstr(line, *argv) != NULL) != except){
                if(number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found;
}