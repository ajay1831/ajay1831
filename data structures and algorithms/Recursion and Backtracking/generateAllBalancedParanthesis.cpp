/* https://www.youtube.com/watch?v=eyCj_u3PoJE
https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/

Total number of valid paranthesis = cat(n) 

TC: O(n*nth catalan number) 
SC: O(2*n) (recursion tree depth)

The complexity of this code is O(n * Cat(n)) where Cat(n) is the nth Catalan number. 
There are Cat(n) possible valid strings that are valid combinations of parenthesis and for each a string of length n is created.

https://en.wikipedia.org/wiki/Catalan_number
https://stackoverflow.com/questions/37385964/time-complexity-for-combination-of-parentheses
https://www.codingninjas.com/studio/library/generate-parentheses
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void generateAllBalancedParanthesis(int left, int right, string &s)
{
	if(left==0 && right==0)
	{
		cout<<s<<endl;
		return;
	}
	else
	{
		// pick left '{'. left can only be picked if available
		if(left!=0)
		{
			s.push_back('{');
			generateAllBalancedParanthesis(left-1, right, s);
			s.pop_back();
		}
		
		// pick right '}'.but right can only be picked if it is availale and we have used left already means left count should be less then right
		if(right!=0 && right>left)
		{
			s.push_back('}');
			generateAllBalancedParanthesis(left, right-1, s);
			s.pop_back();
		}
	}
}

int main()
{
	int n;
	cout<<"enter n"<<endl;
	cin>>n;
	
	string s = "";
	generateAllBalancedParanthesis(n, n, s);
	
	return 0;
}
