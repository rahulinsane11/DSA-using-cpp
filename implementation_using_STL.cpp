#include <bits/stdc++.h>
using namespace std;

void print_stack(stack <int> s)
{
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

int main()
{
	stack <int> s;
	s.push(3);
	s.push(2);
	s.push(1);
	print_stack(s);
	cout << "size= " << s.size() << endl;
	cout << "top= " << s.top() << endl;
	s.pop();
	print_stack(s);
}