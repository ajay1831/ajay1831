/* https://www.geeksforgeeks.org/the-knights-tour-problem/

TC: There are N2 Cells and for each, we have a maximum of 8 possible moves to choose from, so the worst running time is O(8N^2).

SC: O(N^2) recursion tree depth
Note:
No order of the xMove, yMove is wrong, but they will affect the running time of the algorithm drastically. 
For example, think of the case where the 8th choice of the move is the correct one, and before that our code ran 7 different wrong paths. 
It’s always a good idea a have a heuristic than to try backtracking randomly. 
Like, in this case, we know the next step would probably be in the south or east direction, then checking the paths which lead their first is a better strategy.

Note that Backtracking is not the best solution for the Knight’s tour problem. See the below article for other better solutions. 
The purpose of this post is to explain Backtracking with an example. 
https://www.geeksforgeeks.org/warnsdorffs-algorithm-knights-tour-problem/

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &board, int n)
{
	if(x>=0 && x<n && y>=0 && y<n && board[x][y]==0)
		return true;
	return false;
}

bool knightTour(int x, int y, int next_number, vector<vector<int>> &board, int *nextX, int *nextY, int n)
{
	if(next_number==n*n+1)
	{
		return true;
	}
	else
	{
		for(int i=0;i<8;i++)
		{
			int next_x = x + nextX[i];
			int next_y = y + nextY[i];
			if(isSafe(next_x, next_y, board, n))
			{
				board[next_x][next_y]=next_number;
				if(knightTour(next_x, next_y, next_number+1, board, nextX, nextY, n)==true)
					return true;
				else 
					board[next_x][next_y]=0;
			}
		}
	}
	
	return false;
}

int main()
{
	int n = 8;
	int current_number = 1;
	vector<vector<int>> board(n, vector<int>(n, 0));
	board[0][0]=current_number;
	
	/* no output if i use this order
	https://stackoverflow.com/questions/70438850/does-knight-tour-problem-solve-depend-on-sequence-of-knight-move#:~:text=The%20knight%20is%20moved%20so,revisit%20any%20square%20already%20visited.
	
	int nextX[8]={1,  1, -1, -1, 2,  2, -2, -2};
	int nextY[8]={2, -2,  2, -2, 1, -1,  1, -1};
	*/

	// lucky move sequence, need to remember for interviews
	int nextX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
    int nextY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 
 
    
	if(knightTour(0, 0, current_number+1, board, nextX, nextY, n)==true)
	{
		for(int i=0;i<board.size();i++)
		{
			for(int j=0; j<board[i].size();j++)
				cout<<board[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
