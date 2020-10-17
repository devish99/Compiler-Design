#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>
#include <stack>
using namespace std;
int checkPrecedence(char s);
void infixToPostfix(string s);
int main()
{
	string input;
	cout << "Enter Expression:"<<endl;
	cin >> input;
	infixToPostfix(input);
	_getch();

}

int checkPrecedence(char s)
{
	if (s == '^')
		return 3;
	else if (s == '*' || s == '/')
		return 2;
	else if (s == '+' || s == '-')
		return 1;
	else return -1;
}

void infixToPostfix(string s)
{
	stack<char> stk;
	stk.push('T');
	int l = s.length();
	string final;
	for (int i = 0; i < l; i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			final += s[i];
		}
		else if (s[i] == '(')
		{
			stk.push('(');
		}
		else if (s[i] == ')')
		{
			while (stk.top() != 'T' && stk.top() != '(')
			{
				final += stk.top();
				stk.pop();
			}
			if (stk.top() == '(')
			{
				stk.pop();
			}
		}
		else
		{
			while (stk.top() != 'T' && (checkPrecedence(s[i]) <= checkPrecedence(stk.top())))
			{
				final += stk.top();
				stk.pop();
			}
			stk.push(s[i]);
		}
	}

	while (stk.top() != 'T')
	{
		final += stk.top();
		stk.pop();
	}

	cout << "POSTFIX IS: " << final;
}