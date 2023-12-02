//https://www.youtube.com/watch?v=eQCS_v3bw0Q&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=7

/*
Time Complexity
The time complexity of the solution depends on the number of subsequences that satisfy the conditions. 
Since we need to generate all possible subsequences, the time complexity is exponential. 
Specifically, it can be represented as O(2^n), where n is the length of the input array.

This is because for each element in the array, we have two choices: either include it in the subsequence or exclude it. 
As a result, the number of recursive calls grows exponentially with the input size.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// this solution doesn't handle duplicate subsetes/subsequences in result but question is not asking for that so its okay.
// TC: O(2^n) each element has 2 choices , picked up or not, in worst case we consider all possible subseqences
// SC: O(n) recursion tree depth
int countAllSubSequencesWithGivenSum(int index, int n, int *arr, int current_sum, int req_sum)
{
	if(index==n)
	{
		if(current_sum==req_sum)
		{
			return 1;
		}
		return 0;
	}
	else
	{
		// get the count by picking the current element , means add it to current sum
		// an optimisation can also be done here, if current element itself is greater then required sum then it can never be included, so include it only when it is <= req sum

		int incl=0;
		int excl=0;
		if(arr[index]<=req_sum)
		{
			current_sum+=arr[index];
			incl = countAllSubSequencesWithGivenSum(index+1, n, arr, current_sum, req_sum);
			
			current_sum-=arr[index]; // whenever we include an element, make sure to remove it for next calls
		}
		
		// get the count by not picking the current element, means do not add it in sum 
		excl = countAllSubSequencesWithGivenSum(index+1, n, arr, current_sum, req_sum);
		
		return incl+excl;

	}
}

int main()
{
	int arr[]={1,1, 2,1};
	int len=sizeof(arr)/sizeof(int);
	
	int sum;
	cout<<"enter required sum"<<endl;
	cin>>sum;
	
	cout<<" number of subsets/subsequence with given count is "<<countAllSubSequencesWithGivenSum(0, len, arr, 0, sum);
	return 0;
}
