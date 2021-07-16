#include <bits/stdc++.h>
using namespace std;

stack <int> st;

void print_stack(stack <int> st)
{
	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

void insert_at_bottom(int x)	
{
	int a;
	if(st.empty())
		st.push(x);
	else
	{
		a=st.top();
		st.pop();
		insert_at_bottom(x);
		st.push(a);
	}
}

void reverse() // T.C.=O(n^2) // for every element O(n) we pick it up and insert in bottom to insert in bottom we shift O(n) elements.
{
	int x;
	if(!st.empty())
	{
		x=st.top(); // hold the items in func. call stack until stack becomes empty
		st.pop();
		reverse();

		insert_at_bottom(x); // insert all items held in func. call stack 1 by 1 from bottom to top
	}
}

int main()
{
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	print_stack(st);
	reverse();
	print_stack(st);
}