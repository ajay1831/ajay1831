//https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=11
//https://www.youtube.com/watch?v=u40eYbmT9zg&list=PLjkkQ3iH4jy82KRn9jXeFyWzvX7sqYrjE&index=11 

// I/P: array is given which can have duplicate elements, target sum is given, 
// O/P: need to return all unique combinations and element is allowed only once to be included and combinations should be in sorted order

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC: O(2^n) each element has 2 choices , picked up or not, in worst case we consider all possible subseqences
// SC: O(n) in worst case it considers all elements 
void printAllUniqueSubSequences(int index, int n, int *arr, vector<int> &v)
{	
	if(index==n)
	{
		for(auto el: v)
			cout<<el<<" ";
		cout<<endl;
		return;
	}
	
	// pick the current element , means add it to current sum and in vector also.
	
	v.push_back(arr[index]);
	printAllUniqueSubSequences(index+1, n, arr, v);
	v.pop_back();
	
	// don't pick the current element, and if this element is not picked then we should not pick repeated elements,
	while(index+1 < n && arr[index+1]==arr[index])
		index++;
	printAllUniqueSubSequences(index+1, n, arr, v);
}

int main()
{
	int arr[]={1,2,3}; //all distinct elements given
	int len=sizeof(arr)/sizeof(int);
	
	sort(arr, arr+len);
	
	vector<int> v;
	printAllUniqueSubSequences(0, len, arr, v);
	return 0;
}


