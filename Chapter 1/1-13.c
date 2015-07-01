#include<stdio.h>
#define IN 1
#define OUT 0
main()
{
	char c;
	int i,j,wc=0,size[50],nc=0,state;
	state = IN;
	while ((c = getchar()) != EOF) {
		
		nc++;
		if (c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
		}
		
		if (state == OUT) {
			state = IN;
			size[wc]=nc-1;
			nc=0;
			wc++;
		}
	}
	printf("\n___________Histogram of Length of words__________\n\n");
	for(i = 0;i<wc;i++)
	{
		printf("%d  | ",i+1);
		for(j=0;j<size[i];j++)
		{
			printf("*");
			
			
		}
		printf("%d\n",size[i]);
	}
}
		
		
