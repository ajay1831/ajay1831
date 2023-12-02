// https://www.geeksforgeeks.org/recursive-function-check-string-palindrome/



#include<iostream>
using namespace std;

// TC: O(n)
// SC: O(1)
bool isPalindromeIterative(string &s)
{
	int start=0;
	int end=s.size()-1;
	
	while(start<=end)
	{
		if(s[start]!=s[end])
			return false;
		start++;
		end--;	
	}
}

// TC: O(n)
// SC: O(n)
bool isPalindrome(string &s, int start, int end)
{
	if(start>=end)
		return true;
	if(s[start]!=s[end])
		return false;
	else
		return isPalindrome(s, start+1, end-1);
}

int main()
{
	string str;
	cout<<"enter string"<<endl;
	cin>>str;
	
	cout<<"using recursion"<<endl;
	if(isPalindrome(str, 0, str.size()-1))
		cout<<"given string is palindrome"<<endl;
	else
		cout<<"given string is not palindrome"<<endl;
		
	cout<<"using iteration"<<endl;
	if(isPalindromeIterative(str))
		cout<<"given string is palindrome"<<endl;
	else
		cout<<"given string is not palindrome"<<endl;

	return 0;
}
