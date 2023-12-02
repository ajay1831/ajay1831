// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}

// TC: O(n)
// SC: O(1)
void reverseArrayIterative(int *arr, int len)
{
	int start=0;
	int end=len-1;
	while(start<end)
	{
		swap(&arr[start], &arr[end]);
		start++;
		end--;
	}
}

// TC: O(n/2) ~ O(n)
// SC: O(n/2) ~ O(n)
void reverseArrayRecursive(int *arr, int start , int end)
{
	if(start>=end)
		return;
	else
	{
		swap(&arr[start], &arr[end]);
		reverseArrayRecursive(arr, start+1, end-1);
	}
}

// TC: O(n/2) ~ O(n)
// SC: O(n/2) ~ O(n)
void reverseArrayRecursiveSingleParameter(int *arr, int start, int len)
{
	if(start>=len/2)
		return;
	else
	{
		swap(&arr[start], &arr[len-1-start]);
		reverseArrayRecursiveSingleParameter(arr, start+1, len);	
	}
	
}

void printArray(int *arr, int len)
{
	for(int i=0;i<len;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int arr[]={1,2,3,4,5,6};
	int len=sizeof(arr)/sizeof(arr[0]);
	
	cout<<"original array"<<endl;
	printArray(arr, len);
	
	reverseArrayIterative(arr, len);
	cout<<"reversed array iterative way"<<endl;
	printArray(arr, len);
	
	reverseArrayRecursive(arr, 0, len-1);
	cout<<"reversed array recursive way"<<endl;
	printArray(arr, len);
	
	reverseArrayRecursiveSingleParameter(arr, 0, len);
	cout<<"reversed array recursive way"<<endl;
	printArray(arr, len);
	
}
