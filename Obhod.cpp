#include "Header.h"

struct Obhod {
	void obhod(bitGraph& Obj,int from, int to, int n)
	{
		int min1 = 0, min2 = 0;
		Obj.Dist[from] = 0;
		LookForShortestPath(Obj, to, n, min1, min2);
		int parnode = Obj.Parent[to];
		MinPush(Obj, parnode);
	}
	int LookForShortestPath(bitGraph& Obj,int to,int n, int min1,int min2) {
		for (int i = 0; i != n; i++)
		{
			int minV = 100000;
			Sorting(Obj, n, minV, min1, min2, i);
			Obj.visited[min2] = true;
			ParentAssign(Obj, n, min2);
		}
		if (Obj.Dist[to] == 100000)
		{
			return 0;
		}
	}
	void Sorting(bitGraph& Obj, int n, int &minV, int &min1, int &min2, int i)
	{
		for (int k = 0; k < n; k++)
		{
			if ((minV > Obj.Dist[k]) & (!Obj.visited[k]))
			{
				minV = Obj.Dist[k];
				min1 = i;
				min2 = k;
			}
		}
	}
	void ParentAssign(bitGraph& Obj, int n, int min2) {
		for (int k = 0; k < n; k++)
		{
			if ((Obj.Value[min2][k] != (-1)) & (Obj.Dist[k] > (Obj.Dist[min2] + Obj.Value[min2][k])))
			{
				Obj.Dist[k] = Obj.Dist[min2] + Obj.Value[min2][k];
				Obj.Parent[k] = min2;
			}
		}
	}
	void MinPush(bitGraph& Obj, int parnode) {
		while (parnode != Obj.StartFrom)
		{
			Obj.minNum.push_back(parnode);
			parnode = Obj.Parent[parnode];
		}
	}
};
