#include <iostream>
using namespace std;

#define MAX 100

class Stack
{
	int top;
public:
	int a[MAX];
	Stack() { top=-1; }
	bool push(int x);
	int pop();
	int peek();
	bool is_empty();
};

bool Stack::push(int x)
{
	if(top>=MAX-1)
	{
		cout << "OVERFLOW ";
		return false;
	}
	else
	{
		top++;
		a[top]=x;
		cout << x << " pushed into stack\n";
		return true;
	}
}

int Stack::pop()
{
	if(top<0)
	{
		cout << "UNDERFLOW ";
		return 0;
	}
	else
	{
		int p=a[top];
		top--;
		return p;
	}
}

int Stack::peek()
{
	if(top<0)
	{
		cout << "stack is empty ";
		return 0;
	}
	else
		return a[top];
}

bool Stack::is_empty()
{
	if(top>=0)
		return false;
	else
		return true;
}

int main()
{
	class Stack s;
	s.push(1);
    s.push(2);
    cout << s.peek() << " at the top of stack\n";
	s.push(3);
	cout << s.is_empty() << "\n";
	cout << s.pop() << " popped out of stack\n";
	cout << s.pop() << " popped out of stack\n";
	cout << s.pop() << " popped out of stack\n";
	cout << s.pop() << "\n";
	cout << s.is_empty() << "\n";
}