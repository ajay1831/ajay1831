//https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=11
//https://www.youtube.com/watch?v=u40eYbmT9zg&list=PLjkkQ3iH4jy82KRn9jXeFyWzvX7sqYrjE&index=11 

// I/P: array is given which can have duplicate elements, target sum is given, 
// O/P: need to return all unique combinations and element is allowed only once to be included and combinations should be in sorted order

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC: O(2^n) each element has 2 choices , picked up or not, in worst case we consider all possible subseqences
// SC: O(n) in worst case it considers all elements 
void printAllUniqueSubSequencesWithGivenSum(int index, int n, int *arr, int current_sum, int req_sum, vector<int> &v)
{
	if(current_sum>req_sum)
		return;
	
	if(index==n)
	{
		if(current_sum==req_sum)
		{
			for(auto el: v)
				cout<<el<<" ";
			cout<<endl;
		}
		return;
	}
	
	// pick the current element , means add it to current sum and in vector also.
	// an optimisation can also be done here, if current element itself is greater then required sum then it can never be included, so include it only when it is <= req sum

	if(arr[index]<=req_sum)
	{
		current_sum+=arr[index];
		v.push_back(arr[index]);
		printAllUniqueSubSequencesWithGivenSum(index+1, n, arr, current_sum, req_sum, v);
		
		current_sum-=arr[index]; // whenever we include an element, make sure to remove it for next calls
		v.pop_back();
	}
	
	// don't pick the current element, and if this element is not picked then we should not pick repeated elements,
	while(index+1 < n && arr[index+1]==arr[index])
		index++;
	printAllUniqueSubSequencesWithGivenSum(index+1, n, arr, current_sum, req_sum, v);
}

int main()
{
	int arr[]={10,1,2,7,6,1,5}; //all distinct elements given
	int len=sizeof(arr)/sizeof(int);
	
	sort(arr, arr+len);
	
	int sum;
	cout<<"enter required sum"<<endl;
	cin>>sum;
	
	vector<int> v;
	printAllUniqueSubSequencesWithGivenSum(0, len, arr, 0, sum, v);
	return 0;
}


