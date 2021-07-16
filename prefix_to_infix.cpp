#include <bits/stdc++.h>
using namespace std;

string prefix_to_infix(string s)
{
	string a,b;
	stack <string> st;
	for(int i=s.length()-1; i>=0; i--) // scan RIGHT to LEFT
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
			st.push("(" + a + s[i] + b + ")"); // A operator B
		}
	}
	return st.top();
}

int main()
{
	string s1="*-A/BC-/AKL";
	cout << prefix_to_infix(s1) << endl;
	string s2="*+ab/ef";
	cout << prefix_to_infix(s2) << endl;
}