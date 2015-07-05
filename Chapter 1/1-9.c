/*Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.*/

#include<stdio.h>
main()
{
	int nb=0;
	char c;
	while((c=getchar())!= '\n' ) {	
		while(c == ' ') {
			c = getchar();
			nb=1;
		}
		if(nb>0) {
			putchar(' ');
			nb=0;
		}
		putchar(c);
	}
}

