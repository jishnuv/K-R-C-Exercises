/*Write a function reverse(s) that reverses the character string s . Use it to
write a program that reverses its input a line at a time.*/
#include <stdio.h>

#define MAXLINE 1000	 /* maximum input line size */

int get_line(char s[], int lim);
void reverse(char input[], int start, int end);

int main() 
{
    int len = 0; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse(line, 0, len - 1);
        printf("%s", line);
    }
    return 0;
}

void reverse(char input[], int start, int end) 
{
    int i, j, temp;
    for (i = start, j = end; i < j; i++, j--) {
        temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }

}

/* get_line: read a line s, return length */
int get_line(char s[], int lim) 
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}
