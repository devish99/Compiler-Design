#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
char in[10],ch[10],p[10],pb[10][10];
int i,j,n,f;

// Number of Production Rules
cout<<"\nEnter number of productions: ";
cin>>n;

// Taking Production Rules
for(i=0;i<n;i++)
{
cout<<"\nEnter Production "<<i+1<<" : ";
cin>>p[i];
cout<<p[i]<<"->";
cin>>pb[i];
cout<<"\n";
}
for(i=0;i<n;i++)
{
for(j=0;j<3;j++)
{
if(p[i]==pb[0][j])
{
pb[0][j]=pb[i][0];
cout<<"\n";
}
}
}

// Taking Input String
cout<<"\nEnter the input string: ";
cin>>in;
i=0;
for(j=0;j<n;j++)
{
if(pb[0][j]==in[i])
{
f++;
i++;
}
}

// Printing Final Results
if(f==3)
{
cout<<"\nACCEPTED!";
}
else
{
cout<<"\nNOT ACCEPTED!";
}
return 0;
}