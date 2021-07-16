#include <bits/stdc++.h>
using namespace std;

string postfix_to_infix(string s)
{
	string a,b;
	stack <string> st;
	for(int i=0; i<s.length(); i++) // scan LEFT to RIGHT
	{
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) // push the operands
		{
			string op(1,s[i]); // convert character to string // string class has a constructor that allows us to specify size of 
			st.push(op);  // string as first parameter and character to be filled in given size as second parameter.
		}
		else
		{
			a=st.top();
			st.pop();
			b=st.top();
			st.pop();
			st.push("(" + b + s[i] + a + ")"); // B operator A
		}
	}
	return st.top();
}

int main()
{
	string s1="ab*c+";
	cout << postfix_to_infix(s1) << endl;
	string s2="ab+ef/*";
	cout << postfix_to_infix(s2) << endl;
}