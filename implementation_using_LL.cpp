#include <bits/stdc++.h>
using namespace std;

class StackNode
{
public:
	int data;
	StackNode *next;
};

StackNode* new_node(int newdata)
{
	StackNode *newnode=new StackNode();
	newnode->data=newdata;
	newnode->next=NULL;
	return newnode;
}

int is_empty(StackNode *head)
{
	if(head==NULL)
		return 1; // stack is empty
	return 0; // stack is not empty
}

void push(StackNode **headref,int newdata)
{
	StackNode *newnode=new_node(newdata);
	newnode->next=*headref;
	*headref=newnode;
	cout << newdata << " pushed into stack\n";
}

int pop(StackNode **headref)
{
	if(is_empty(*headref))
		return INT_MIN;  // INT_MIN specifies that an integer variable cannot store any value below this limit.
	StackNode *temp=*headref;
	*headref=temp->next;
	int popped=temp->data;
	free(temp);
	return popped;
}

int peek(StackNode *head)
{
	if(is_empty(head))
		return INT_MIN;
	return (head)->data;
}

int main()
{
	StackNode *head=NULL;
	push(&head,3);
	push(&head,2);
	push(&head,1);
	cout << pop(&head) << " popped from stack\n";
	cout << peek(head) << " is the top of stack\n";
	cout << pop(&head) << " popped from stack\n";
	cout << pop(&head) << " popped from stack\n";
	cout << pop(&head) << " popped from stack\n";
	cout << peek(head) << " is the top of stack\n";
}