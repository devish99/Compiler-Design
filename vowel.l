%{
#include<stdio.h>
int vowel=0;
int cons=0;
%}
%%
"a"|"e"|"i"|"o"|"u"|"A"|"E"|"I"|"O"|"U" {printf(" VOWEL ");vowel++;}
[a-zA-z] {printf(" CONSONANT ");cons++;}
%%
int yywrap()
{
return 1;
}
main()
{
printf("Enter String\n");
yylex();
printf("Vowel=%d and Consonant=%d",vowel,cons);
}