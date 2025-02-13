%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line = 1;
%}

%option noyywrap

KEY    auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
OPR  \+|\-|\*|\/|%|\+\+|\-\-|<|>|<=|>=|==|!=|&&|\|\||!|&|\||\^|~|<<|>>|=|\+=|\-=|\*=|\/=|%=|&=|\|=|\^=|>>=|<<=
SYMBOLS     ,|\(|\)|\[|\]|\{|\}|;|:|\.
IDENTIFIERS [a-zA-Z_][a-zA-Z0-9_]*
NUM    [0-9]+(\.[0-9]*)?
STR     \"[^\"]*\"
CHAR  '\\?.'
COMMENTS    \/\*([^*]|\*+[^\/])*\*+\/|\/\/.*
WHITESPACE [ \t]+
NEWLINE    \n
INVALID_NUM [0-9]+[a-zA-Z]+

%%

{KEY}    { printf("Keyword: %s\n", yytext); }
{OPR}   { printf("Operator: %s\n", yytext); }
{SYMBOLS}     { printf("Punctuation: %s\n", yytext); }
{NUM}     { printf("Constant: %s\n", yytext); }
{STR}     { printf("String: %s\n", yytext); }
{CHAR}  { printf("Constant: %s\n", yytext); }
{IDENTIFIERS} { printf("Identifier: %s\n", yytext); }

{INVALID_NUM} { printf("LEXICAL ERROR at Line %d: Invalid numeric: %s\n", line, yytext); }

{COMMENTS}    { /* Ignore comments */ }
{WHITESPACE} { /* Ignore whitespace */ }
{NEWLINE}    { line++; }
.            { printf("LEXICAL ERROR at Line %d: Invalid token: %s\n", line, yytext); }

%%

int main() {
    yylex();
    return 0;
}

