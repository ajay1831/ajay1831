// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

#include<iostream>
using namespace std;

// TC: O(2^n) -> each call is making 2 recursive calls (exponential)
// SC: O(n) -> depth of recursion tree
int fibRecursive(int n)
{
	if(n<=1)
		return n;
	return fibRecursive(n-1)+fibRecursive(n-2);
}

// TC:O(n)
// SC: O(1)
int fibIterative(int n)
{
	if(n<=1)
		return n;
	int a=0;
	int b=1;
	int c;
	
	for(int i=2;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	
	return c;
}

int main()
{
	int n;
	cout<<"enter nth"<<endl;
	cin>>n;
	
	cout<<"fibonaci number using recursion is "<<fibRecursive(n)<<endl;
	cout<<"fibonaci number using loop is "<<fibIterative(n);
	
	
	return 0;
}
