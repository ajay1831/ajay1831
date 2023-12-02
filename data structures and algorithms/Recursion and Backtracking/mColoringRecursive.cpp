/* https://www.youtube.com/watch?v=wuVwUK25Rfc&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=18
https://www.geeksforgeeks.org/m-coloring-problem/

TC: O(V^m) (for each node we are trying m colors)
SC: O(V) + O(V) (first for recursion tree depth and next is to hold colors array)

*/

#include<iostream>
#include<bits/stdc++.h>
#define V 4

using namespace std;

bool isSafe(int node, int col, bool graph[V][V], int *colors)
{
	for(int i=0;i<V;i++)
	{
		if(i!=node && graph[i][node]==1 && colors[i]==col)
			return false;
	}
	return true;
}

bool help(int node, int m, bool graph[V][V], int *colors)
{
	if(node==V)
	{
		return true;
	}
	else
	{
		for(int col = 1; col<=m;col++)
		{

			if(isSafe(node, col, graph, colors))
			{
				colors[node]=col;
				if(help(node+1, m, graph, colors)==true)
					return true;
				colors[node]=0;
			}
		}
		return false;
	}
}

void graphColoring(bool graph[V][V], int m)
{
	int colors[V]={0};
	if(help(0, m, graph, colors)==true)
	{
		cout<<"coloring is possible on all vertices"<<endl;
		for(int i=0;i<V;i++)
			cout<<colors[i]<<" ";
	}
	else
	{
		cout<<"coloring is not possible"<<endl;
	}
}

int main()
{
 
    /* Create following graph and test
       whether it is 3 colorable
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
 
    // Number of colors
    int m = 3;
 
    // Function call
    graphColoring(graph, m);
    return 0;
}
