/*Program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines.*/
#include <stdio.h>

#define MAXLINE 1000	 /* maximum input line size */

int main() {
    int i, j = 0, count, sp;
    int len = 0; /* current line length */
    char c, line[MAXLINE]; /* current input line */
    char temp[MAXLINE];

    while ((c = getchar()) != EOF) {
        line[len] = c;
        len++;
    }
    line[len] = '\0';
    printf("%d\n", len);
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
        temp[count] = '\0';
        sp = 0;
        //printf("%s",temp);
        for (i = count - 1; temp[i] == ' ' || temp[i] == '\t'; i--) {
            sp++;
        }
        j = delete(line, j, sp);
        len -= sp;
        //printf("no of tail %d \n",sp);
        //printf("%d\n",len);
    }
    printf("%s", line);
}

int delete(char input[], int end, int space) {
    int i, j = end + 1;
    input[end - space] = '\n';
    for (i = (end - space) + 1; input[i] != '\0'; i++, j++) {
        input[i] = input[j];
    }
    return (end - space) + 1;
}

