#include <bits/stdc++.h>
using namespace std;

string reverse_individual_words_in_string(string s)
{
	int len=s.length();
	string rs;
	for(int i=0; i<len; i++)
	{
		stack <char> st;
		while(s[i]!=' ' && i<len-1)
		{
			st.push(s[i]);
			i++;
		}
		while(!st.empty())
		{
			rs=rs+st.top();
			st.pop();
		}
		rs=rs+s[i];
	}
	return rs;
}

int main()
{
	string s1="abcd efgh pqrs xyz";
	cout << reverse_individual_words_in_string(s1) << endl;
}