/* WIP */

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
    printf("Debug:strcapy (%s, %s):\n\n", s, t);
    while ((*s++ = *t++) != '\0')
       ;
}

int main() {
    int nlines; /*number of input lines to read */
    if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        printf("Debug: Main-before qsort\n");
        qsort(lineptr, 0, nlines-1);
        printf("Write lines\n");
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
    printf("Debug: Readlines\n");
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /*delete new line..*/
            printf("Readlines:p:%d\nline:%s", p, line);
            char *o = line;
            qsort(&o, 0, strlen(line));
            strcpy(p, line);
            lineptr[nlines++] = p;
            printf("lineptr:%d\n", lineptr);
        }
    printf("returning: %d\n", nlines);
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    printf("Debug: writelines\n");
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* OLD
int getline(char s[], int lim) {
    printf("Debug: getline\n");
    int c, i;

    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n';i++)
        s[i] = c;
    if( c == '\n'){
        s[i]=c;
        i++;
    }
    s[i] = '\0';
    printf("exit getline: %s\t%d\n", s, i);
    return i;
}
*/
int getline(char *s, int max){
    printf("Debug: getline function.\n");
    if(fgets(s, max, stdin)== NULL)
        return 0;
    else {
        printf("getline return: %s\t%d\n", s, strlen(s));
        return strlen(s);
    }
}

void qsort(char *v[], int left, int right){
    printf("Debug: qsort\n");
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
    printf("swap done. qsort\n");
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j){
    printf("Debug: swap\n");
    char a[MAXLEN];
    printf("*temp = a\n");
    char *temp = a;
    printf("temp = v[i]\n");
    temp = v[i];
    printf("v[i] = v[j]\n");
    v[i] = v[j];
    printf("v[j]=temp\n");
    v[j] = temp;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = &allocbuf[0];

char *alloc(int n){
    printf("Debug: alloc\n");
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        printf("Debug - alloc: %d\t%c\tn:%d\n",allocp, allocp, n);
        return allocp - n;
    }
    else {
        return 0;
    }
}
