#include <bits/stdc++.h>
using namespace std;

stack<int> sort_stack(stack <int> st1) // smallest element at the top in sorted stack // T.C.=O(n^2)
{
	int temp;
	stack <int> st2;
	while(!st1.empty())
	{
		temp=st1.top();
		st1.pop();
		while(!st2.empty() && st2.top()<temp) // until the st2 becomes empty or st2 top > temp
		{
			st1.push(st2.top());  // pop an element from st2 and push into st1
			st2.pop();
		}
		st2.push(temp);
	}
	return st2;
}

void print_stack(stack <int> st)
{
	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

int main()
{
	stack <int> st1;
	st1.push(3);	st1.push(5);	st1.push(1);	st1.push(4);	st1.push(2);	st1.push(8);
	print_stack(st1);
	stack <int> sst1= sort_stack(st1);
	print_stack(sst1);
	stack <int> st2;
	st2.push(34);	st2.push(3);	st2.push(31);	st2.push(98);	st2.push(92);	st2.push(23);
	print_stack(st2);
	stack <int> sst2= sort_stack(st2);
	print_stack(sst2);
}