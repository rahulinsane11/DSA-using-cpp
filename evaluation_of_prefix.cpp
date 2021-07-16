#include <bits/stdc++.h>
using namespace std;

int evaluate_prefix(string s) // works for single digit numbers
{
	int a,b;
	stack <int> st;
	for(int i=s.length()-1; i>=0; i--) // scan from R to L
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
				
				case '+': st.push(a+b); break;
				case '-': st.push(a-b); break;
				case '*': st.push(a*b); break;
				case '/': st.push(a/b); break;
				case '^': st.push(pow(a,b)); break; // pow(a,b) = a^b
			}
		}
	}
	a=st.top();
	st.pop();
	return a;
}

int main()
{
	string s1="-+8/632";
	cout << evaluate_prefix(s1) << endl;
	string s2="-+7*45+20";
	cout << evaluate_prefix(s2) << endl;
	string s3="^2^23";
	cout << evaluate_prefix(s3) << endl;
}