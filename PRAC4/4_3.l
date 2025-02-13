%{
	#include<stdio.h>
	int cc, cw, cl;
%}

%option noyywrap

%%

\n	{cl++; }
[^ \t\n]+	{cw++; cc+=yyleng; }
.	{cc++; }

%%

int main()
{
	yylex();
	printf("Characters : %d \n",cc);
	printf("Words : %d \n",cw);
	printf("Line : %d \n",cl);
	return 0;
}
