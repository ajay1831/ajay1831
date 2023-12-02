// https://www.geeksforgeeks.org/generating-all-possible-subsequences-using-recursion/
// https://www.youtube.com/watch?v=AxNNVECce8c&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=6

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC: O(2^n) * n (here extra n is to print the sub sequences) each element has 2 choices, to be picked or not
// SC: O(n) depth of recursion tree
void printAllSubsequences(int index, int n, int *arr, vector<int> &v)
{
	if(index==n)
	{
		if(v.size()==0)
			cout<<"{}"<<endl;
		else
		{
			for(auto el: v)
				cout<<el<<" ";
		}
		cout<<endl;
		return;
	}
	else
	{
		//pick the element at index and recursively call for next elements
		v.push_back(arr[index]);
		printAllSubsequences(index+1, n, arr, v);
		v.pop_back(); // whenever we pick an element, make sure to remove it back, it is must for further calls
		
		// don't pick the current element and recursively call for next elements
		printAllSubsequences(index+1, n, arr, v);
	}
}

int main()
{
	int arr[]={1,2,3};
	int len=sizeof(arr)/sizeof(int);
	
	vector<int> v; // vector to hold subsequences
	printAllSubsequences(0, len, arr, v);
	
	return 0;
}
