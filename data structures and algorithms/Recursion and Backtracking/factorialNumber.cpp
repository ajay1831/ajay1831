// https://www.geeksforgeeks.org/program-for-factorial-of-a-number/

#include<iostream>
using namespace std;

// TC: O(n)
// SC: O(1)
long long int factorialIterative(int n)
{
	if(n==0||n==1)
		return 1;
	else
	{
		long long int fact=1;
		for(int i=1;i<=n;i++)
		{
			fact*=i;
		}
		return fact;
	}
}

// TC: O(n)
// SC: O(n)
long long int factorialRecursive(int n)
{
	if(n==0||n==1)
		return 1;
	else
		return factorialRecursive(n-1)*n;
}

int main()
{
	int n;
	cout<<"Enter N"<<endl;
	cin>>n;
	
	cout<<"Factorial Iterative way: "<< factorialIterative(n)<<endl;
	cout<<"Factorial Recursive way: "<< factorialRecursive(n)<<endl;
	
	return 0;
}
