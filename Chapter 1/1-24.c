/*program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments.*/
#include<stdio.h>
#define MAXSIZE 2000

int main() 
{
    int i = 0, check[6] = {0};
    int len = 0;
    char c, buffr[MAXSIZE];


    while ((c = getchar()) != EOF) {
        buffr[len] = c;
        len++;
    }
    buffr[len] = '\0';
    while (i < len) {
        if (buffr[i] == '(')
            check[0]++;
        else if (buffr[i] == ')')
            check[0]--;

        if (buffr[i] == '[')
            check[1]++;
        else if (buffr[i] == ']')
            check[1]--;

        if (buffr[i] == '{')
            check[2]++;
        else if (buffr[i] == '}')
            check[2]--;

        if (buffr[i] == '\'')
            check[3]++;

        if (buffr[i] == '\"')
            check[4]++;
        if (buffr[i] == '/' && buffr[i + 1] == '*') {
            check[5]++;
            i++;
        } else if (buffr[i] == '*' && buffr[i + 1] == '/') {
            check[5]--;
            i++;
        }

        i++;
    }

    if (check[5] != 0)
        printf("Unterminated comment\n");
    if (check[0] != 0)
        printf("Unmatched () detected\n");
    if (check[1] != 0)
        printf("Unmatched [] detected\n");
    if (check[2] != 0)
        printf("Unmatched {} detected\n");
    if ((check[3] % 2) != 0)
        printf("Unmatched single quote detected\n");
    if ((check[4] % 2) != 0)
        printf("Unmatched double quote detected\n");
    return 0;
} 
