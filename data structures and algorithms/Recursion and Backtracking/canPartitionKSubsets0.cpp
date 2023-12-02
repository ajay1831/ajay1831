/* https://www.youtube.com/watch?v=h_6MldQ8vB8&list=PLjkkQ3iH4jy82KRn9jXeFyWzvX7sqYrjE&index=20

if we use normal method where each element some choices like here each element has K choices, it can be part of 1st bucket, or 2nd bucket or kth bucket/subset.
then TC will be O(K^n).
we can reduce it by using another approach where we will try to pick the buckets and fill the elements in it.

TC: O(2^(N*K))
SC: O(N)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool canPartitionKSubsets(int index, int *arr, int len, int subset_number, int total_subsets, int current_subset_sum, int required_sum_per_subset, vector<int> &alreadyPicked)
{
	if(subset_number==total_subsets+1)
		return true;
	if(current_subset_sum > required_sum_per_subset)
		return false;
	if(current_subset_sum==required_sum_per_subset)
		return canPartitionKSubsets(0, arr, len, subset_number+1, total_subsets, 0, required_sum_per_subset, alreadyPicked);
	if(index>=len)
		return false;

	if(alreadyPicked[index]==1)
		return canPartitionKSubsets(index+1, arr, len, subset_number, total_subsets, current_subset_sum, required_sum_per_subset, alreadyPicked);
	else
	{
		// pick
		current_subset_sum+=arr[index];
		alreadyPicked[index]=1;
		int op1 = canPartitionKSubsets(index+1, arr, len, subset_number, total_subsets, current_subset_sum, required_sum_per_subset, alreadyPicked);
		
		// skip
		current_subset_sum-=arr[index];
		alreadyPicked[index]=0;
		int op2 = canPartitionKSubsets(index+1, arr, len, subset_number, total_subsets, current_subset_sum, required_sum_per_subset, alreadyPicked);
		
		return op1||op2;
	}
}

int main()
{
	int arr[]={4,3,1,3,4,3,1,2};
	int len = sizeof(arr)/sizeof(int);
	int k;
	
	cout<<"enter number of partition required"<<endl;
	cin>>k;
	
	if(k==1)
		cout<<"possible";
	else if(k>len)
		cout<<"not possible";
	else
	{
	
		int total_sum=0;
		for(int i=0;i<len;i++)
			total_sum+=arr[i];
		
		vector<int> alreadyPicked(len, 0);
		
		int required_sum_per_subset = total_sum/k;
		
		if(total_sum%k!=0)
			cout<<"k equal partitions are not possible"<<endl;
		else
		{
			cout<<canPartitionKSubsets(0, arr, len, 1, k, 0, required_sum_per_subset, alreadyPicked);
		}
	}
	return 0;
}
