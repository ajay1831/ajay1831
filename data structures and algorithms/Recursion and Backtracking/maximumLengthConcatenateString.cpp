/* https://www.youtube.com/watch?v=DIJQ8zLeVEk&list=PLjkkQ3iH4jy82KRn9jXeFyWzvX7sqYrjE&index=21

https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

TC: O(2^n * k) (extra k because we are running loop for each string and assume avg size of string is k)
SC: O(n) (recursion depth)
*/
#include<iostream>
#include<bits/stdc++.h>
#define MAX_CHAR 26
using namespace std;

bool isSafe(int *visited, string &current_string)
{
	// first check if current string itself has any repeated characters, if yes, then it is not safe to consider
	int self_visited[MAX_CHAR]={0};
	
	for(int i=0;i<current_string.size();i++)
	{
		if(self_visited[current_string[i]-'a']==1)
			return false;
		else
			self_visited[current_string[i]-'a']=1;
	}
	
	// now check if it has any character which is already visited in previous strings, if yes then it is not safe to consider
	for(int i=0;i<current_string.size();i++)
	{
		if(visited[current_string[i]-'a']==1)
			return false;
	}
	
	return true;	
}

int maximumLengthConcatenateStrings(int index, vector<string> &v, int len, int *visited)
{
	if(index==v.size())
		return len;
	else
	{
		string current_string=v[index];
		if(isSafe(visited, current_string))
		{
			// pick the string and get the maximum possible length 
			len+=current_string.size();
			for(int i=0;i<current_string.size();i++)
			{
				visited[current_string[i]-'a']=1;
			}
			int op1 = maximumLengthConcatenateStrings(index+1, v, len, visited);
			
			// don't pick this string, so remove its length from len and also mark visited values back to 0
			len-=current_string.size();
			for(int i=0;i<current_string.size();i++)
			{
				visited[current_string[i]-'a']=0;
			}
			int op2 = maximumLengthConcatenateStrings(index+1, v, len, visited);
			
			// return maximum length between picking and not picking
			return max(op1, op2);
		}
		else
			return maximumLengthConcatenateStrings(index+1, v, len, visited);
	}
	
}
int main()
{
	vector<string> v={"cha", "r","act", "ers"};
	int visited[MAX_CHAR] = {0};
	cout<<maximumLengthConcatenateStrings(0, v, 0, visited);
	
	return 0;
}
