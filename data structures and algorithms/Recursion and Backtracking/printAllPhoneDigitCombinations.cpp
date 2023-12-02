#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void combination(int index, string &s, string &temp, vector<string> &ans, unordered_map<char,string> &m)
{
	if(index==s.size())
	{
		ans.push_back(temp);
		return;
	}
	else
	{
		string str = m[s[index]];
		for(int i=0;i<str.size();i++)
		{
			temp.push_back(str[i]);
			combination(index+1, s, temp, ans, m);
			temp.pop_back();	
		}	
	}
}

int main()
{
	string s="37";
	vector<string> ans;
	string temp;
	
	unordered_map<char, string> m;
	m['2']="abc";
	m['3']="def";
	m['4']="ghi";
	m['5']="jkl";
	m['6']="mno";
	m['7']="pqrs";
	m['8']="tuv";
	m['9']="wxyz";
	
	combination(0, s, temp, ans, m);
	
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}
