/*
https://www.geeksforgeeks.org/print-1-to-n-without-using-loops/

Time Complexity: O(n)
Space Complexity: O(n) recursion stack depth

*/

#include<iostream>
using namespace std;

void printOneToNRecursive(int i, int n)
{
	if(i>n)
		return;
	else
	{
		cout<<i<<endl;
		printOneToNRecursive(i+1, n);
	}
}

void printOneToNBacktracking(int n)
{
	if(n==0)
		return;
	else
	{
		printOneToNBacktracking(n-1);
		cout<<n<<endl;
	}
}

int main()
{
	int n;
	cout<<"Enter N"<<endl;
	cin>>n;
	
	cout<<"using backtracking"<<endl;
	printOneToNBacktracking(n);
	
	cout<<endl<<"using recursion"<<endl;
	printOneToNRecursive(1, n);
	return 0;
}
