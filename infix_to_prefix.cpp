#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
	if(c=='^')
		return 3;
	else if(c=='*' || c=='/')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	else
		return-1;
}

int associativity(char c)
{
	if(c=='^') // RIGHT to LEFT
		return 2;
	else if(c=='*' || c=='/' || c=='+' || c=='-') // LEFT to RIGHT
		return 1;
	else 
		return -1;
}

string infix_to_prefix(string s)
{
	char c;
	stack <char> st;
	string pre;
	reverse(s.begin(),s.end());
	for(int i=0; i<s.length(); i++)
	{
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) // add operand to prefix string
			pre=pre+s[i];
		else if(s[i]==')') // push ')' into stack
			st.push(s[i]);
		else if(s[i]=='(') 
		{
			while(st.top()!=')' && !st.empty()) // keep on popping and adding operators to prefix string until ')' is reached
			{
				c=st.top();
				st.pop();
				pre=pre+c;
			}
			if(st.top()==')') // pop ')'
				st.pop();
		}
		else
		{
			while(!st.empty() && precedence(s[i])<=precedence(st.top())) // keep on popping and adding operators to prefix string until an operator with
			{                                                            // lower precedence is reached
				if(precedence(s[i])==precedence(st.top()) && associativity(s[i])==1) // if incoming  operator with equal precedence and R to L asoociativity
					break;                                                           // with the stack top then simply push it into the stack
				c=st.top();
				st.pop();
				pre=pre+c;
			}
			st.push(s[i]); // push the operator if its precedence is greater than the top of stack
		}
	}
	while(!st.empty()) // pop the remaining operators from the stack and add them to prefix string
	{
		c=st.top();
		st.pop();
		pre=pre+c;
	}
	reverse(pre.begin(),pre.end()); // reverse the prefix againa
	return pre;
}

int main()
{
	string s1= "a+b*(c^d-e)^(f+g*h)-i";
	cout << infix_to_prefix(s1) << endl;
	string s2= "k+l-m*n+(o^p)*w/u/v*t+q";
	cout << infix_to_prefix(s2) << endl;
	string s3= "k+l-m*n+(o^p)*w/u/v*t+q^j^a";
	cout << infix_to_prefix(s3) << endl;
	string s4= "(a-b/c)*(a/k-l)";
	cout << infix_to_prefix(s4) << endl;
	string s5= "a-b*c+d";
	cout << infix_to_prefix(s5) << endl;
	string s6= "(a+b)*(c+d)";
	cout << infix_to_prefix(s6) << endl;
	string s7= "a+b*c-d/e^f";
	cout << infix_to_prefix(s7) << endl;
	string s8= "a^b^c";
	cout << infix_to_prefix(s8) << endl;
}