//https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=12

// I/P: array is given
// O/P: need to return sums of all possible subsequences/subsets in increasing order of sums value

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC: O(2^n) + 2^nLog(2^n) to sort the result
// SC: O(n) + O(2^n) -> to store the results, total subsequences will be 2^n 
void sumsOfAllSubSequences(int index, int n, int *arr, int sum, vector<int> &v)
{	
	if(index==n)
	{
		v.push_back(sum);
		return;
	}
	
	// pick the current element , means add it to current sum.

	sumsOfAllSubSequences(index+1, n, arr, sum+arr[index], v);
	
	sumsOfAllSubSequences(index+1, n, arr, sum, v);
}

int main()
{
	int arr[]={1,2,3}; //all distinct elements given
	int len=sizeof(arr)/sizeof(int);
	
	vector<int> v;
	sumsOfAllSubSequences(0, len, arr, 0, v);
	
	sort(v.begin(), v.end());
	
	
	for(auto el: v)
		cout<<el<<" ";

	return 0;
}


