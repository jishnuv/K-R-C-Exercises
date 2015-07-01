#include<stdio.h>
main()
{
	char c;
	int i,j,size[128]={0};
	while( (c=getchar()) != EOF )
	{
		size[c]++;
	}
	for(i=33;i<128;i++)
	{
		if(size[i]>0)
		{
			printf("%c  | ",i);
			for(j=0;j<size[i];j++)
			{
				printf("*");
			
			}
			printf("%d\n",size[i]);
		}
	}
}
