/*program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments.*/
#include<stdio.h>
#define MAXSIZE 3000
char stack[300];
int top = -1;

int skipper(char input[], int start, int mod);
void push(char );
char pop();
int main() 
{
    int i = 0;
    int len = 0;
    char c, buffr[MAXSIZE];


    while ((c = getchar()) != EOF) {
        buffr[len] = c;
        len++;
    }
    buffr[len] = '\0';
    while (i < len) {
    	
       	if (buffr[i] == '(' || buffr[i] == '[' || buffr[i] == '{' )
            push(buffr[i]);
        else if(buffr[i] == ')') {
        	if(pop() != '(')
        		printf("out of order parentheses\n");
        }
        else if(buffr[i] == ']') {
        	if(pop() != '[')
        		printf("out of order bracket\n");
        }
        else if(buffr[i] == '}') {
        	if(pop() != '{')
        		printf("out of order brace\n");
        }

        if (buffr[i] == '\'')
            i = skipper(buffr, i+1, 3);

        if (buffr[i] == '\"')
            i = skipper(buffr, i+1, 2);
        if (buffr[i] == '/' && (buffr[i + 1] == '*')) {
            i = skipper(buffr,i+2,0);
        }
        if (buffr[i] == '/' && (buffr[i+1]=='/')) {
            i = skipper(buffr,i+2,1);
        }
        i++;
    }
    if(top > -1)
    	printf(".......syntax errors........\n");
    return 0;
} 

void push(char c)
{
	top++;
	stack[top] = c;
}

char pop()
{
	char c;
	if(top == -1)
		return '\0';
	c = stack[top];
	top--;
	return c;
}
	
int skipper(char input[], int start, int mod)
{	
	int i = start;
	if(mod == 0) {
		while(input[i] != '*' && input[i + 1] != '/') {
			i++;
		}
		return i+1;
	}
	else if(mod == 1) {
		while(input[i] != '\n') {
			i++;
		}
		return i;
	}
	else if(mod == 2) {
		while(input[i] != '\"') {
			i++;
		}
		return i;
	}
	else if(mod == 3) {
		while(input[i] != '\'') {
			i++;
		}
		return i;
	}
	return start;
}
