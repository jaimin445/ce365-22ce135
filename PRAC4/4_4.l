%option noyywrap

%{
	#include<stdio.h>
	int c, lower=0, upper=0, digit=0, symbol=0;
%}

%%

[a-z]	{lower=1; c++; }
[A-Z]	{upper=1; c++; }
[0-9]	{digit=1; c++; }
[*;#$@]	{symbol=1; c++; }
[\n]	{
		if (c>=9 && c<=15 && (lower && upper && digit && symbol)==1)
		{
			printf("Valid password");
		}
		else
		{
			printf("Invalid password");
		}
	}

%%

int main()
{
	yylex();
}
