/*Program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing*/
#include<stdio.h>
#define TABWIDTH 4
#define MAXSIZE 1000

int main() 
{
    int i = 0, j = 0, insp = 0, nb, ns;
    int len = 0;
    char c, buffr[MAXSIZE];
    while ((c = getchar()) != EOF) {
        insp = 0;
        if (c == ' ') {
            while (c == ' ' || c == '\t') {
                if (c == ' ')
                    insp++;
                if (c == '\t')
                    insp += 4;
                c = getchar();

            }
            nb = insp / TABWIDTH;
            ns = insp % TABWIDTH;
            /*printf("total space  %d : ",insp);
            printf("no tabs inserted %d  : ",nb);
            printf("no space inserted %d  : ",ns);*/
            for (i = 0; i < nb; i++) {
                buffr[len] = '\t';
                len++;
            }
            for (i = 0; i < ns; i++) {
                buffr[len] = ' ';
                len++;
            }
        }
        buffr[len] = c;
        len++;
    }
    buffr[len] = '\0';
    printf("\n");
    printf("%s", buffr);

    return 0;
}
