#include "Header.h"

struct Obhod {
	int obhod(bitGraph& Obj,int from, int to, int n)
	{
		int min1 = 0, min2 = 0;
		Obj.Dist[from] = 0;
		for (int i = 0; i != n; i++)
		{
			int minV = 100000;
			for (int k = 0; k < n; k++)
			{
				if ((minV > Obj.Dist[k]) & (!Obj.visited[k]))
				{
					minV = Obj.Dist[k];
					min1 = i;
					min2 = k;
				}
			}
			Obj.visited[min2] = true;
			for (int k = 0; k < n; k++)
			{
				if ((Obj.Value[min2][k] != (-1)) & (Obj.Dist[k] > (Obj.Dist[min2] + Obj.Value[min2][k])))
				{
					Obj.Dist[k] = Obj.Dist[min2] + Obj.Value[min2][k];
					Obj.Parent[k] = min2;
				}
			}
		}
		if (Obj.Dist[to] == 100000)
		{
			return 0;
		}
		int parnode = Obj.Parent[to];
		while (parnode != Obj.StartFrom)
		{
			Obj.minNum.push_back(parnode);
			parnode = Obj.Parent[parnode];
		}
	}
};
