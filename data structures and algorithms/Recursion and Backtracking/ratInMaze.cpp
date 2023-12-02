/* https://www.geeksforgeeks.org/rat-in-a-maze/

https://www.youtube.com/watch?v=XiJ0Qq1LD5g
https://www.youtube.com/watch?v=bLGZhJlt4y0

TC: O(4^N) (N=n*n, if draw a recursion tree, each node or cell has 4 direction to try and total cells are n*n)
SC: O(N) (N=n*n, in worst case recursion depth will be n*n if all cells are 1)

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &visited, int n)
{
	if(i>=0 && i<n && j>=0 && j<n && maze[i][j]==1 && visited[i][j]==0)
		return true;
	return false;
}

void ratInMaze(int i, int j, int *nextI, int *nextJ, vector<vector<int>> &maze, vector<vector<int>> &visited, char *dir, string &path, vector<string> &ans, int n)
{
	if(i==n-1 && j==n-1)
	{
		ans.push_back(path);
		return;
	}
	else
	{
		for(int k=0;k<4;k++)
		{
			int next_i = i+ nextI[k];
			int next_j = j + nextJ[k];
			if(isSafe(next_i, next_j, maze, visited, n))
			{
				char direction = dir[k];
				path.push_back(direction);
				visited[next_i][next_j]=1;
				ratInMaze(next_i, next_j, nextI, nextJ, maze, visited, dir, path, ans, n);
				path.pop_back();
				visited[next_i][next_j]=0;		
			}
		}
	}
}

int main()
{
	vector<vector<int>> maze = { {1,0,0,0},
								 {1,1,0,1},
							 	 {1,1,0,0},
								 {0,1,1,1}};
								 
	if(maze[0][0]==0)
	{
		cout<<"not possible to reach destination"<<endl;
	}
	else
	{
		int n = 4;
		char dir[4]={'D', 'L', 'R', 'U'};
		int nextI[4]={1, 0, 0, -1};
		int nextJ[4]={0, -1, 1, 0};
		
		string path="";
		vector<string> ans;
		vector<vector<int>> visited(n, vector<int>(n,0));
		
		visited[0][0]=1;
		ratInMaze(0,0, nextI, nextJ, maze, visited, dir, path, ans, n);
		
		for(int i=0;i<ans.size();i++)
		{
			for(int j=0;j<ans[i].size();j++)
			{
				cout<<ans[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
