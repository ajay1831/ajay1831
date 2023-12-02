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
void uniquePermutationsUsing(int index, int *arr, int len)
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
		unordered_set<int> st; // to hold the unique elements which is already considered for a given index
		for(int i=index; i<len;i++)
		{
			if(st.find(arr[i])==st.end()) // try to find if current element is duplicate means same element is already placed at given index , then continue else add it into set and perform recursion
				st.insert(arr[i]);
			else
				continue;
			swap(&arr[index], &arr[i]);
			uniquePermutationsUsing(index+1, arr, len);
			swap(&arr[index], &arr[i]);
		}
	}
}

int main()
{
	int arr[]={1,2,1};
	int len=sizeof(arr)/sizeof(int);
	
	uniquePermutationsUsing(0, arr, len);
	
	return 0;
}
