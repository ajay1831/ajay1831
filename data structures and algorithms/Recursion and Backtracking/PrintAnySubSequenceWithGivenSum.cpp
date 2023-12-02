//https://www.youtube.com/watch?v=eQCS_v3bw0Q&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=7


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC: O(2^n) each element has 2 choices , picked up or not, in worst case we consider all possible subseqences
// SC: O(n) recursion tree depth
bool printAnySubSequenceWithGivenSum(int index, int n, int *arr, vector<int> &v, int current_sum, int req_sum)
{
	if(index==n)
	{
		if(current_sum==req_sum)
		{
			
			for(auto el: v)
				cout<<el<<" ";
			return true;
		}
		return false;
	}
	else
	{
		// pick the current element , means add it to current sum and also add it in vector
		// an optimisation can also be done here, if current element itself is greater then required sum then it can never be included, so include it only when it is <= req sum
		
		if(arr[index]<=req_sum)
		{
			current_sum+=arr[index];
			v.push_back(arr[index]);
			if(printAnySubSequenceWithGivenSum(index+1, n, arr, v, current_sum, req_sum) == true)
				return true;
			
			current_sum-=arr[index]; // whenever we include an element, make sure to remove it for next calls
			v.pop_back();
		}
		
		// don't pick the current element, means do not add it in sum and do not add in vector. 
		if(printAnySubSequenceWithGivenSum(index+1, n, arr, v, current_sum, req_sum) == true)
			return true;
	}
	return false;
}

int main()
{
	int arr[]={1,1, 2,1};
	int len=sizeof(arr)/sizeof(int);
	
	vector<int> v;
	int sum;
	cout<<"enter required sum"<<endl;
	cin>>sum;
	
	printAnySubSequenceWithGivenSum(0, len, arr, v, 0, sum);
	return 0;
}
