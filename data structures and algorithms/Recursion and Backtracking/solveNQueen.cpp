/* https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=16
https://takeuforward.org/data-structure/n-queen-problem-return-all-distinct-solutions-to-the-n-queens-puzzle/

TC: 
to place 1st queen we have n options (1st queen can be placed in any row)
to place 2nd queen we have n-1 options now (because in same row 2 queen can not be placed and one row is already occupied by 1st queen so just n-1 rows left)
to place 3rd queen we have n-2 options
to place nth queen we have 1 option

so n*(n-1)*(n-2)*....1 = O(n!)

SC: O(n) (depfth of recursion tree will be number of rows so O(n)) + O(n^2) to store recursion result so overall its O(n^2)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n)
{
	// save original row n col values
	int duprow = row;
	int dupcol = col;
	
	// now check if current queen at row, col attacks any other queen in left diagonal
	while(duprow>=0 && dupcol>=0)
	{
		if(board[duprow][dupcol]=='Q')
			return false;
		duprow--;
		dupcol--;
	}
	
	// reset again 
	duprow=row;
	dupcol=col;
	
	// now check left colums from current col but same row
	while(dupcol>=0)
	{
		if(board[duprow][dupcol]=='Q')
			return false;
		dupcol--;
	}
	
	// reset again 
	duprow=row;
	dupcol=col;
	
	// now check if queent at current row , col attacks any other queen in bottom left diagonal
	while(dupcol>=0 && duprow<n)
	{
		if(board[duprow][dupcol]=='Q')
			return false;
		dupcol--;
		duprow++;
	}
	
	return true;
}
void solveNQueens(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
	if(col==n)
	{
		ans.push_back(board);
		return;
	}
	else
	{
		for(int row=0;row<n;row++)
		{
			if(isSafe(row, col, board, n))
			{
				board[row][col]='Q';
				solveNQueens(col+1, board, ans, n);
				board[row][col]='.';
			}
		}
	}
}

int main() 
{

	int n = 4; // we are taking 4*4 grid and 4 queens
  
  	vector<vector<string>> ans;
	vector<string> board(n);
	string s(n, '.');
	for(int i=0;i<n;i++)
		board[i]=s;

    solveNQueens(0, board, ans, n);
	for(int i = 0; i < ans.size(); i++) 
	{
		cout << "Arrangement " << i + 1 << "\n";
	    for (int j = 0; j < ans[0].size(); j++) 
		{
			cout << ans[i][j];
	      	cout << endl;
	    }
	    cout << endl;
	}
	return 0;
}
