/* https://www.geeksforgeeks.org/rat-in-a-maze/

https://www.youtube.com/watch?v=XiJ0Qq1LD5g
https://www.youtube.com/watch?v=bLGZhJlt4y0

TC: O(N * 4^N) (N=n*n, we are running n*n loop for searching the cell which can start with word's first letter and once we found we call recursive word search method which takes 4^n time because each cell has 4 options to try 
and in worst case when all cells are having same character we will end up with this complexiy)
SC: O(N) (N=n*n, in worst case recursion depth will be n*n if all cells are 1)

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, vector<vector<char>> &board, vector<vector<int>> &visited, int n, string &word, int index)
{
	//if(i>=0 && i<n && j>=0 && j<n && board[i][j]==word[index] && board[i][j]!='$')
	if(i>=0 && i<n && j>=0 && j<n && board[i][j]==word[index] && visited[i][j]==0)
	
		return true;
	return false;
}

bool wordSearch(int i, int j, int *nextI, int *nextJ, vector<vector<char>> &board, vector<vector<int>> &visited, string &word, int index, int n)
{
	if(index==word.size()-1)
	{
		return true;
	}
	else
	{
		for(int k=0;k<4;k++)
		{
			int next_i = i+ nextI[k];
			int next_j = j + nextJ[k];
			if(isSafe(next_i, next_j, board, visited, n, word, index+1))
			{
				visited[next_i][next_j]=1;
				//char ch = board[next_i][next_j];
				//board[next_i][next_j]='$';
				if(wordSearch(next_i, next_j, nextI, nextJ, board, visited, word, index+1, n)==true)
					return true;
				visited[next_i][next_j]=0;
				//board[next_i][next_j]=ch;		
			}
		}
	}
	return false;
}

int main()
{
	vector<vector<char>> board = { {'q','v','m','h'},
								   {'d','e','s','i'},
							 	   {'d','g','f','g'},
								   {'e','c','p','n'}};
	
	int n = 4;
	
	int nextI[4]={1, 0, 0, -1};
	int nextJ[4]={0, -1, 1, 0};
	
	string word="design";
	vector<vector<int>> visited(n, vector<int>(n,0));
	
	for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board[i].size();j++)
		{
			if(board[i][j]==word[0]){
				visited[i][j]=1;
				//board[i][j]='$';  // can be done like this without need of visited matrix. remove all commented code and comment all visited code
				if(wordSearch(i,j, nextI, nextJ, board, visited, word, 0, n)==true)
					cout<<"found at "<<i<<","<<j<<endl;
				}
		}
	}

	return 0;
}
