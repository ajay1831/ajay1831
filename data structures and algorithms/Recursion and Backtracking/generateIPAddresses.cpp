/* https://www.geeksforgeeks.org/program-generate-possible-valid-ip-addresses-given-string/

this problem is exatly similar to partition palindrome

Given a string containing only digits, restore it by returning all possible valid IP address combinations.
A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0

*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool isValid(string t)
{
    long long int num = stoll(t);
    if(num>=0 && num<=255)
        return true;
    return false;
}

void help(int index, string &s, vector<string> &temp, vector<vector<string>> &ans)
{
    if(index==s.size() && temp.size()==4)
    {
		ans.push_back(temp);
        return;
    }
    else
    {
        for(int i=index;i<s.size();i++)
        {
            if(isValid(s.substr(index, i-index+1)))
            {
                temp.push_back(s.substr(index, i-index+1));
                help(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
}

vector<vector<string>> generateIps(string &s) {
    vector<vector<string>> ans;
    vector<string> temp;
    help(0, s, temp, ans);
    return ans;
}

int main()
{
	string s="25525511135";
	vector<vector<string>> ans = generateIps(s);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<".";
		cout<<endl;
	}
	return 0;
}
