#include "Header.h"

bitGraph::bitGraph(int n)
{
	Value = new int* [RebN = n];
	for (int i = 0; i < n; i++)
	{
		Parent[i] = i;
		Dist[i] = 100000;
		visited[i] = false;
	}
	for (int i = 0; i < n; i++)
	{
		int* row = Value[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			row[j] = -1;
		}
	}
}

bitGraph::~bitGraph() 
{
	for (int i = 0; i < RebN; i++) 
	{
		delete Value[i];
	}
	delete Value;
}





