#include <bits/stdc++.h>
using namespace std;

void next_greater_element(int a[],int n) // print -1 if no greater element is found
{
	stack <int> st;
	int b[n];
	for(int i=n-1; i>=0; i--) // scan from R to L
	{
		while(!st.empty() && st.top()<=a[i]) // pop the elements until the top > current element or stack becomes empty
			st.pop();
		if(st.empty()) // if stack becomes empty than no greater eleemt is found
			b[i]=-1;
		else           // the top of stack becomes the next greater element of the current element
			b[i]=st.top();
		st.push(a[i]); // push current element onto the stack
	}
	for(int i=0; i<n; i++)
		cout << a[i] << "->" << b[i] << ", ";
	cout << endl;
}

int main()
{
	int n;
	int a1[]={11,13,21,3};
	n=sizeof(a1)/sizeof(a1[0]);
	next_greater_element(a1,n);
	int a2[]={4,5,2,25};
	n=sizeof(a2)/sizeof(a2[0]);
	next_greater_element(a2,n);
	int a3[]={4,5,2,25,10};
	n=sizeof(a3)/sizeof(a3[0]);
	next_greater_element(a3,n);
	int a4[]={13,7,6,12};
	n=sizeof(a4)/sizeof(a4[0]);
	next_greater_element(a4,n);
}