#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
using namespace std;

int n,m=0,p,i=0,j=0;
char a[10][10],f[10];
void follow(char c);
void first(char c);
int main(){

int i;
char c,ch;

cout<<"Enter the number of productions:\n";
cin>>n;
cout<<"Enter the productions:\n";
for(i=0;i<n;i++)
cin>>a[i];

m=0;
cout<<"Enter the element to find its FIRST and FOLLOW:";
cin>>c;
first(c);
cout<<"FIRST("<<c<<") = {";
for(i=0;i<m;i++)
cout<<f[i];
cout<<"}\n";
strcpy(f," ");

m=0;
follow(c);
cout<<"FOLLOW("<<c<<") = {";
for(i=0;i<m;i++)
cout<<f[i];
cout<<"}\n";
return(0);
}

void first(char c)
{
int k;
if(!isupper(c))
f[m++]=c;
for(k=0;k<n;k++)
{
if(a[k][0]==c)
{
if(a[k][2]=='$')
follow(a[k][0]);
else if(islower(a[k][2]))
f[m++]=a[k][2];
else first(a[k][2]);
}
}
}
void follow(char c)
{
if(a[0][0]==c)
f[m++]='$';
for(i=0;i<n;i++)
{
for(j=2;j<strlen(a[i]);j++)
{
if(a[i][j]==c)
{
if(a[i][j+1]!='\0')
first(a[i][j+1]);
if(a[i][j+1]=='\0' && c!=a[i][0])
follow(a[i][0]);
}
}
}
}
