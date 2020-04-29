#include <stdio.h>
#include <string.h>
#include <conio.h>
int l,c=0,size=0,a=0,j;
char ch;
char str[100];
void count()
{
 int i;
 for (i = l-1; str[i] != ' '; i--)
 {
 ch = str[i];
 ascii(ch);
 }
}
void ascii(char c)
{
 if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
 a=a+1;
 else
 {
 c =c+1;
 }
}
int main()
{
 printf("Enter an instruction:");
 gets(str);
 l = strlen(str);
 if(l<=3)
 size=1;
 else
 count();
 if(a==1)
 size=1;
 if(a==2)
 size=2;
 if(c>2)
 size=3;
 if(c>0 && c<=2)
 {
 size=2;
 }
 if(c == 0 && a ==0)
 {
 size =1;
 }
 if(a+c==4)
 {
 size=3;
 }
 printf("Size = %d",size);
}
