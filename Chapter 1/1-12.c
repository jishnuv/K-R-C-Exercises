/*Exercise 1-12. Write a program that prints its input one word per line.*/

#include<stdio.h>
main()
{
	char c;
	while((c=getchar())!='\n')
	{
		if(c==' ')
		{
			printf("\n");
		}
		else
			putchar(c);
	}
}



