%{
	#include<stdio.h>
%}

%%

[0-9]+		{ printf("%s \n", yytext); }
.	;

%%

int yywrap(void)
{
	return 1;
}

void main()
{
	yylex();
}
