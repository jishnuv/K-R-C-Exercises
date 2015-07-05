//1.8 Write a program to count blanks, tabs, and newlines.

#include<stdio.h>
main()
{
	int nblanks=0, ntabs=0, newline=0;
	char c;
	while((c=getchar())!= EOF ){
		if(c==' ')
			nblanks++;
		else if(c=='\t')
			ntabs++;
		else if(c=='\n')
			newline++;
		
	}
	printf("---------------------------------\n");
	printf("Number of blanks : %d\n",nblanks);
	printf("Number of tabs : %d\n",ntabs);
	printf("Number of newlines : %d\n",newline);
}


