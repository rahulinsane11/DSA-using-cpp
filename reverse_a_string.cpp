#include <bits/stdc++.h>
using namespace std;

string reverse_string(string s)
{
	int len=s.length();
	string rs;
	stack <char> st;
	for(int i=0; i<len; i++)
		st.push(s[i]);
	for(int i=0; i<len; i++) // pop elements from stack and add them to the new string
	{
		rs=rs+st.top(); 
		st.pop();
	}
	return rs;
}

int main()
{
	string s1="abcde";
	cout << reverse_string(s1) << endl;
	string s2="pqrs";
	cout << reverse_string(s2) << endl;
}