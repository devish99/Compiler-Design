#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
int ninputs;

int check(char, int); //function declaration
int dfa[10][10];
char c[10], mystring[10];
int main()
{
    int nstates, nfinals;
    int f[10];
    int i, j, s = 0, final = 0;
    cout<<"Enter the number of states that your dfa consist of: \t";
    cin>>nstates;
    cout<<"Enter the number of input symbol that dfa have: \t";
    cin>>ninputs;
    cout<<"\nEnter input symbols: \n";
    for (i = 0; i < ninputs; i++)
    {
     cout<<i+1<<"  Input: \t";
     cin>>c[i];
    }
    cout<<"\n\nEnter number of final states: \t";
    cin>>nfinals;

    for (i = 0; i < nfinals; i++)
    {
      cout<<"\nFinal state "<<i+1<<": q";
      cin>>f[i];
    }

     cout<<"\n\nDefine transition rule as (initial state, input symbol ) = final state\n";
     for (i = 0; i < ninputs; i++)
     {
         for (j = 0; j < nstates; j++)
         {
                       cout<<"\n(q"<<j<<", "<<c[i]<<") = q";
                       cin>>dfa[i][j];
         }
     }

     
         i = 0;
     cout<<"\n\nEnter Input String:  ";
     cin>>mystring[i];

     while (mystring[i] != 0)
         if ((s = check(mystring[i++], s)) < 0)
             break;
     for (i = 0; i < nfinals; i++)
         if (f[i] == s)
             final = 1;
     if (final == 1)
        cout<<"\nValid string!";
     else
        cout<<"\nINVALID STRING !";

    
     


}

int check(char b, int d)
{
    int j;
    for (j = 0; j < ninputs; j++)
        if (b == c[j])
            return (dfa[d][j]);
    return -1;
}