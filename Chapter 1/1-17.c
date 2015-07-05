/*Program to print all input lines that are longer than 80 characters.*/
#include <stdio.h>

#define MAXLINE 1000	 /* maximum input line size */

int main()
{
    int j = 0, count;
    int len = 0; /* current line length */
    char c, line[MAXLINE]; /* current input line */
    char temp[MAXLINE];

    while ((c = getchar()) != EOF) {
        line[len] = c;
        len++;
    }
    line[len] = '\0';
    printf("Lines longer than 80 characters are \n");
    while (j < len) {
        count = 0;
        while (line[j] != '\0' && line[j] != '\n') {

            temp[count] = line[j];
            count++;
            j++;
            if (line[j] == '\n') {
                j++;
                break;
            }

        }
        temp[count + 1] = '\0';
        if (count > 80)
            printf("%s\n", temp);
    }

    return 0;
}

