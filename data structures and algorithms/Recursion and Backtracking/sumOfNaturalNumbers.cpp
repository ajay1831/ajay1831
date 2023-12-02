// https://www.geeksforgeeks.org/sum-of-natural-numbers-using-recursion/

#include<iostream>
using namespace std;

// TC: O(1)
// SC: O(1)
int formulaBased(int n)
{
	return n*(n+1)/2;
}

// TC: O(n)
// SC: O(1)
int loopBased(int n)
{
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=i;
	return sum;
}

// TC: O(n)
// SC: O(n)
int recursiveFunctional(int n)
{
	if(n==0)
		return 0;
	else
		return n + recursiveFunctional(n-1);
}

// TC: O(n)
// SC: O(n)
void recursivePrint(int n, int sum)
{
	if(n==0)
	{
		cout<<sum<<endl;
		return;
	}
	else
	{
		recursivePrint(n-1, sum+n);
	}
}

int main()
{
	int n;
	cout<<"enter N"<<endl;
	cin>>n;
	
	cout<<"using formula sum is: ";
	cout<<formulaBased(n);
	
	cout<<endl<<"using loop sum is: ";
	cout<<loopBased(n);
	
	cout<<endl<<"using functional recursion sum is: ";
	cout<<recursiveFunctional(n);
	
	cout<<endl<<"using recursion sum is ";
	recursivePrint(n, 0);
}
