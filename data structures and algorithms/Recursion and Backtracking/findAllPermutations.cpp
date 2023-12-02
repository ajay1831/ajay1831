// https://www.youtube.com/watch?v=YK78FU5Ffjw&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=14
// https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// TC: n!*n (extra n , because for each recursive call we are iterating n times to find which element is available to be picked)
// SC: O(n) + O(n) (one is to store all the elements in a map or picked array)
void permuteUsingMap(int *arr, int len, int *picked, vector<int> &v, vector<vector<int>> &ans)
{
	if(v.size()==len-1)
	{
		ans.push_back(v);
		return;
	}
	else
	{
		for(int i=0;i<len;i++)
		{
			if(!picked[i])
			{
				picked[i]=1;
				v.push_back(arr[i]);
				permuteUsingMap(arr, len, picked, v, ans);
				picked[i]=0;
				v.pop_back();
			}
		}
	}
}

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

// TC: n!*n (extra n , because for each recursive call we are iterating n times)
// SC: O(n) (not using any extra space , only recursion depth is counsidered here)
void permuteUsingSwap(int index, int *arr, int len)
{
	if(index==len)
	{
		for(int i=0;i<len;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		return;
	}
	else
	{
		for(int i=index; i<len;i++)
		{
			swap(&arr[index], &arr[i]);
			permuteUsingSwap(index+1, arr, len);
			swap(&arr[index], &arr[i]);
		}
	}
}

int main()
{
	int arr[]={1,2,3};
	int len=sizeof(arr)/sizeof(int);
	
	/*
	vector<int> v;
	vector<vector<int>> ans;
	int picked[len]={0};
	
	permuteUsingMap(arr, len, picked, v, ans);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	*/
	
	permuteUsingSwap(0, arr, len);
	
	return 0;
}
