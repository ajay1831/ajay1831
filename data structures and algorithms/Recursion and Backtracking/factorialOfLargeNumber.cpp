/*
https://www.geeksforgeeks.org/factorial-large-number/

TC: O(n2)
SC: O(digits in factorial)

*/

#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *prev;
		Node(int d)
		{
			data=d;  
			prev=NULL;
		}
};

void printList(Node *tail)
{
	if(tail==NULL)
		return;
	printList(tail->prev);
	cout<<tail->data;
}

void multiply(int multiplier, Node *tail)
{
	Node *last=tail;
	Node *lastPrev=NULL;
	int carry=0;
	
	while(last!=NULL)
	{
		int val = last->data*multiplier + carry;
		last->data = val%10;
		carry = val/10;
		
		lastPrev=last;
		last=last->prev;
	}
	
	while(carry!=0)
	{
		lastPrev->prev=new Node(carry%10);
		carry=carry/10;
		lastPrev=lastPrev->prev;
	}
}

int main()
{
	int n;
	cout<<"Enter n"<<endl;
	cin>>n;
	
	Node *last=new Node(1);
	for(int i=2;i<=n;i++)
	{
		multiply(i, last);
	}
	
	printList(last);
	
	return 0;
	
}


