/*Program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.*/

#include<stdio.h>
#define  LINESIZE 10
#define MAXSIZE 1000

int main()
{
    int i = 0, j = 0, count = 0;
    int len = 0;
    char c, buffr[MAXSIZE];
    while ((c = getchar()) != EOF) {

        buffr[len] = c;
        len++;
        count++;
        if (count > LINESIZE) {
            count = 0;
            buffr[len] = '\n';
            len++;
        }
    }
    buffr[len] = '\0';
    printf("\n\n");
    printf("%s", buffr);
    return 0;
}
