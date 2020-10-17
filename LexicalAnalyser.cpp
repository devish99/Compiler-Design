#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{

int i,ic=0,m,cc=0,oc=0,j;

char b[30], operators[30], identifiers[30], constants[30];

cout<<"Enter a string : ";
cin>>b;
for(i=0;i<strlen(b);i++)
{

    if(isspace(b[i]))
    
    {
        continue;
    }
    
    else if(isalpha(b[i])){
        identifiers[ic] =b[i];
         ic++;
    }
    else if(isdigit(b[i]))
    {
        m=(b[i]- 0);
        i=i+1;
        while(isdigit(b[i])){
            m=m*10 + (b[i]-'0');
            i++;
        }
        
        i=i-1;
        constants[cc]=m;
        cc++;
    }
     else{
        if(b[i]=='*'){
            operators[oc]='*';
            oc++;
        }
        else if(b[i]=='-'){
            operators[oc]='-';
            oc++;
        }
        else if(b[i]=='+'){
            operators[oc]='+';
            oc++;
        }
         else if(b[i]=='='){
            operators[oc]='=';
            oc++;
        }

  }

}

    cout<<" Identifiers are: ";
     for(j=0;j<ic;j++){
        cout<<identifiers[j];
     }
    cout<<"\n Constants are: ";
     for(j=0;j<cc;j++){
        cout<<constants[j];
     }
    cout<<"\n Operators are: ";
      for(j=0;j<oc;j++)
      {
        cout<<operators[j];
      }

 return 0;
}