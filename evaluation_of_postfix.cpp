#include <bits/stdc++.h>
using namespace std;

int evaluate_postfix(string s) // works for single digit numbers
{
	int a,b;
	stack <int> st;
	for(int i=0; i<s.length(); i++) // scan from L to R
	{
		if(s[i]>='0' && s[i]<='9')
			st.push(s[i]-'0'); // convert the char. into int. and then push into stack 
		else
		{
			a=st.top();
			st.pop();
			b=st.top();
			st.pop();
			switch(s[i])
			{
				
				case '+': st.push(b+a); break;
				case '-': st.push(b-a); break;
				case '*': st.push(b*a); break;
				case '/': st.push(b/a); break;
				case '^': st.push(pow(b,a)); break; // pow(b,a) = b^a
			}
		}
	}
	a=st.top();
	st.pop();
	return a;
}

int main()
{
	string s1="231*+9-";
	cout << evaluate_postfix(s1) << endl;
	string s2="223^^";
	cout << evaluate_postfix(s2) << endl;
}