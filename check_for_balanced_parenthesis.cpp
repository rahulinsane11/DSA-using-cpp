#include <bits/stdc++.h>
using namespace std;

int check_balanced_parenthesis(string s) // T.C.=O(n) ; A.S.=O(n)
{
	char c;
	stack <char> st;
	for(int i=0; i<s.length(); i++)
	{
		if(s[i]=='(' || s[i]=='{' || s[i]=='[')
			st.push(s[i]);
		else if(s[i]==')' || s[i]=='}' || s[i]==']')
		{
			if(st.empty()) // there are no left parenthesis present
				return -1;
			c=st.top();
			st.pop();
			if(s[i]==')' && c!='(')
				return -1;
			else if(s[i]=='}' && c!='{')
				return -1;
			else if(s[i]==']' && c!='[')
				return -1;
		}
	}
	if(st.empty())  // if stack is empty then balanced
		return 1;
	else // if stack is not empty then unbalanced
		return -1;
}

int main()
{
	string s1="{()}[]";
	cout << check_balanced_parenthesis(s1) << endl;
	string s2="[{()}]";
	cout << check_balanced_parenthesis(s2) << endl;
	string s3="[()]{}{[()()]()}";
	cout << check_balanced_parenthesis(s3) << endl;
	string s4="[(])";
	cout << check_balanced_parenthesis(s4) << endl;
	string s5="{[}]";
	cout << check_balanced_parenthesis(s5) << endl;
	string s6="[ a + [ b* (c * d)] + (e * f) ] + { a + [ b* (c * d)] + (e * f) }";
	cout << check_balanced_parenthesis(s6) << endl;
	string s7="}{()";
	cout << check_balanced_parenthesis(s7) << endl;
	string s8="[{(a+b) * (c/d)}]";
	cout << check_balanced_parenthesis(s8) << endl;
}