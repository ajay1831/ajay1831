/* https://www.geeksforgeeks.org/flood-fill-algorithm-implement-fill-paint/
https://www.youtube.com/watch?v=RjO-HDjRMpM&list=PLjkkQ3iH4jy82KRn9jXeFyWzvX7sqYrjE&index=23

TC: O(n*n) (each cell is visited once , even if a call is made , it will return if it is already filled with new color)
SC: O(n*n) (in worst case, each cell is having same color , recursion depth will be n*n)

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void floodFill(int i, int j, vector<vector<int>> &image, int iniColor, int newColor, int n, int *nextI, int *nextJ)
{
	// check if it is boundary
	if(i<0 || i>=n || j<0 || j>=n)
		return;
	
	// check if its not with the same old color
	if(image[i][j]!=iniColor)	
		return;
	
	// check if it is already have new color
	if(image[i][j]==newColor)
		return;
	
	image[i][j]=newColor;
	// try all 4 adjacent cells to fill
	for(int k=0;k<4;k++)
	{
		int next_i = i+ nextI[k];
		int next_j = j + nextJ[k];
		floodFill(next_i, next_j, image, iniColor, newColor, n, nextI, nextJ);
	}
}

int main()
{
	vector<vector<int>> image = { {1,1,0},
								 {2,2,0},
							 	 {2,0,2}};
			
	int sr = 2;
	int sc = 0;
	int newColor;
	
	cout<<"enter new color"<<endl;
	cin>>newColor;
	
	
	cout<<"original image"<<endl;
	for(int i=0;i<image.size();i++)
	{
		for(int j=0;j<image[i].size();j++)
		{
			cout<<image[i][j]<<" ";
		}
		cout<<endl;
	}	
	
	int iniColor = image[sr][sc];
	if(iniColor==newColor)
		cout<<"already colored with new color, can't start else will end up in an infinite loop if iniColor and newColor are same";
	else
	{
		int n = 3;
		
		int nextI[4]={1, 0, 0, -1};
		int nextJ[4]={0, -1, 1, 0};
		
		floodFill(sr, sc, image, iniColor, newColor, n, nextI, nextJ);
		
		cout<<"Filled image:"<<endl;
		for(int i=0;i<image.size();i++)
		{
			for(int j=0;j<image[i].size();j++)
			{
				cout<<image[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
