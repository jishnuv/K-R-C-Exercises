/*Program to remove all comments from a C program. */
#include<stdio.h>
#define MAXSIZE 2000
int delete(char input[], int start, int ch);

int main() 
{
    int i = 0, j = 0, count;
    int len = 0;
    char c, buffr[MAXSIZE];


    while ((c = getchar()) != EOF) {
        buffr[len] = c;
        len++;
    }
    buffr[len] = '\0';
    printf("%d\n", len);
    while (i < len) {
        if (buffr[i] == '/' && buffr[i + 1] == '*') {
            count = 2;
            for (j = i + 2; buffr[j] != '*' && buffr[j + 1] != '/'; j++) {
                count++;
            }
            count += 2;
            i = delete(buffr, i, count);
        }
        if (buffr[i] == '/' && buffr[i + 1] == '/') {
            count = 2;
            for (j = i + 2; buffr[j] != '\n'; j++) {
                count++;
            }

            i = delete(buffr, i, count);
        }

        i++;
    }
    printf("%s", buffr);
    return 0;
}

int delete(char input[], int start, int ch) 
{
    int i = start, j;
    for (j = (start + ch) + 1; input[i] != '\0'; i++, j++) {
        input[i] = input[j];
    }
    return start;
}


