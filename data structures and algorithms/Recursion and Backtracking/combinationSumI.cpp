//https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=10
// I/P is distinict elements, a target sum is also given and allowed to pick up same element again and again

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// TC: O(2^n) each element has 2 choices , picked up or not, in worst case we consider all possible subseqences and also same element can be repeated so can't say exact but
// it will be exponential
// SC: depends on length of the combination, can't predict
void combinationSumI(int index, int n, int *arr, int current_sum, int req_sum, vector<int> &v)
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
	
	// pick the current element , means add it to current sum and in vector also. in next recursion call same element can be considered again so don't increase the index
	// an optimisation can also be done here, if current element itself is greater then required sum then it can never be included, so include it only when it is <= req sum

	if(arr[index]<=req_sum)
	{
		current_sum+=arr[index];
		v.push_back(arr[index]);
		combinationSumI(index, n, arr, current_sum, req_sum, v);
		
		current_sum-=arr[index]; // whenever we include an element, make sure to remove it for next calls
		v.pop_back();
	}
	
	// don't pick the current element, means do not add it in sum and not in vector, directly iterate for next index
	combinationSumI(index+1, n, arr, current_sum, req_sum, v);
}

int main()
{
	int arr[]={2,3,6,7}; //all distinct elements given
	int len=sizeof(arr)/sizeof(int);
	
	int sum;
	cout<<"enter required sum"<<endl;
	cin>>sum;
	
	vector<int> v;
	combinationSumI(0, len, arr, 0, sum, v);
	return 0;
}
