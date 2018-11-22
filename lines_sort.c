#include <stdio.h>
#include <string.h>
#define MAXLEN 1000 /* max input length */
#define MAXLINES 5

char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
int getline(char *, int);
char *alloc(int);


void strcopy(char *s, char *t){
    while ((*s++ = *t++) != '\0')
       ;
}

int main() {
    int nlines; /*number of input lines to read */
    if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("Error: input too big to sort.\n");
        return 1;
    }
}

/* read input lines */
int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /*delete new line..*/
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
}


int getline(char *s, int max){
    if(fgets(s, max, stdin)== NULL)
        return 0;
    else {
        return strlen(s);
    }
}

void qsort(char *v[], int left, int right){
    int i, last;
    void swap(char *v[], int i, int j);

    if(left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j){
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = &allocbuf[0];

char *alloc(int n){
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    }
    else {
        return 0;
    }
}
