/*Program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. */
#include<stdio.h>
#define TABWIDTH 4
#define MAXSIZE 1000

int main() 
{
    int i = 0, j = 0, insp;
    int len = 0;
    char c, buffr[MAXSIZE];
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            insp = len % TABWIDTH;
            for (i = 0; i < insp; i++) {
                buffr[len] = ' ';
                len++;
            }
        } else {
            buffr[len] = c;
            len++;
        }
    }
    buffr[len] = '\0';
    printf("%s", buffr);

    return 0;
}
