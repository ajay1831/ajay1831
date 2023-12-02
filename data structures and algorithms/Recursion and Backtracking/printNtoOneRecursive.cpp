/*
https://www.geeksforgeeks.org/print-n-to-1-without-loop/

Time Complexity: O(n)
Space Complexity: O(n) recursion stack depth

*/

#include<iostream>
using namespace std;

void printNtoOneRecursive(int n)
{
	if(n==0)
		return;
	else
	{
		cout<<n<<endl;
		printNtoOneRecursive(n-1);
	}
}

void printNtoOneBacktracking(int i, int n)
{
	if(i>n)
		return;
	else
	{
		printNtoOneBacktracking(i+1, n);
		cout<<i<<endl;
	}
}

int main()
{
	int n;
	cout<<"Enter N"<<endl;
	cin>>n;
	
	cout<<"using backtracking"<<endl;
	printNtoOneBacktracking(1,n);
	
	cout<<endl<<"using recursion"<<endl;
	printNtoOneRecursive(n);
	
	return 0;	
}
