/* https://www.youtube.com/watch?v=WBgsABoClE0&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=19

https://takeuforward.org/data-structure/palindrome-partitioning/


Time Complexity: O( (2^n) *k*(n/2) )

Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. 
O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

Space Complexity: O(n) + O(k * x)

Reason: The space complexity can vary depending upon the length of the answer. 
k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. 
The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n)

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int start, int end)
{
	while(start<=end)
	{
		if(s[start]!=s[end])
			return false;
		start++;
		end--;
	}
	return true;
}

void partitionStringsPalindrome(int index, string &s, vector<string> &v, vector<vector<string>> &ans)
{
	if(index==s.size())
	{
		ans.push_back(v);
		return;
	}
	else
	{
		for(int i=index;i<s.size();i++)
		{
			if(isPalindrome(s, index, i))
			{
				v.push_back(s.substr(index, i-index+1));
				partitionStringsPalindrome(i+1, s, v,ans);
				v.pop_back();
			}
		}
	}
}

int main()
{
	string s="aaa";
	vector<string> v;
	vector<vector<string>> ans;
	partitionStringsPalindrome(0, s, v, ans);
	
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}
