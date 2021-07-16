#include <iostream>
#include <stack>
using namespace std;

int stock_span(int a[],int n)
{
	int b[n];
	stack <int> st;
	st.push(0);  // push index of first element
	b[0]=1; // span of first element is always 1
	for(int i=1; i<n; i++)
	{
		while(!st.empty() && a[st.top()]<=a[i])
			st.pop();
		if(st.empty()) // a[i] is greater than all elements to its left
			b[i]=i+1;
		else
			b[i]=i-st.top();
		st.push(i);
	}
	for(int i=0;i<n;i++)
		cout << b[i] << " ";
	cout << endl;
}

int main()
{
	int n;
	int a1[]={10,4,5,90,120,80};	
	n=sizeof(a1)/sizeof(a1[0]);
	stock_span(a1,n);
	int a2[]={100, 80, 60, 70, 60, 75, 85};	
	n=sizeof(a2)/sizeof(a2[0]);
	stock_span(a2,n);
}