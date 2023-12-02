/*https://www.youtube.com/watch?v=wT7gcXLYoao&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=21
https://www.geeksforgeeks.org/find-the-k-th-permutation-sequence-of-first-n-natural-numbers/

TC: O(n*n)  (first is because we are picking one element at a time in a loop and second is to erase function)
SC: O(n)

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string kthPermutationSequence(int n, int k)
{
	int fact=1;
	vector<int> numbers;
	for(int i=1;i<=n;i++)
	{
		fact*=i;
		numbers.push_back(i);
	}
	
	if(k>fact)
		return "not possible";
	string ans="";
	
	
	while(true)
	{
		int bucket_size = fact/numbers.size(); // each bucket will hold n!/n elements 
		int bucket_index = k/bucket_size; // once we know size of each bucket , we can divide our k by bucket size to go to bucket index
		
		ans = ans+to_string(numbers[bucket_index]); // bucket index is nothing but element index in numbers array
		numbers.erase(numbers.begin()+bucket_index); // once we have picked up element, now reduce array size, we are left with n-1 elements
		if(numbers.size()==0)
			break;
		fact = bucket_size; // in starting total numbers were n , so fact was n! but since we picked up one element , we need to reduce fact also so new fact will be (n-1)!
		k = k%fact; 
	}
	
	return ans;
}

int main()
{
	int n, k;
	cout<<"enter n and then k";
	cin>>n>>k;
	
	string ans = kthPermutationSequence(n, k-1); // 0 based indexing so 4th means 3rd
	cout<<ans<<endl;
	
	return 0;
}
