#include "Header.h"

struct ShowPath {
	void Path(bitGraph& Obj, int From, int to)
	{
		if (!Obj.minNum.empty())
		{
			cout << "Вес минимального пути = " << Obj.Dist[to] << endl;
			cout << "Кратчайший путь из веришны " << From + 1 << " в вершину " << to + 1 << endl;
			cout << From + 1;
			Minimum(Obj);
			cout << "->" << to + 1;
		}
		else {
			if (Obj.Dist[to] != 100000)
			{
				cout << "Вес минимального пути = " << Obj.Dist[to] << endl;
				cout << "Кратчайший путь из веришны " << From + 1 << " в вершину " << to + 1 << endl;
				cout << From + 1;
				cout << "->" << to + 1;
			}
			else {
				cout << "Путь из вершины " << From + 1 << " в вершину " << to + 1 << " не существует" << endl;
			}
		}
		cout << endl;
	}
	void Minimum(bitGraph& Obj) {
		for (int i = 0; i = Obj.minNum.size(); i++)
		{
			cout << "->";
			cout << Obj.minNum.back() + 1;
			Obj.minNum.pop_back();
		}
	}
};

struct ShowTable {
	void Table(bitGraph& Obj, int n)
	{
		cout << '\n' << "Матрица смежности";
		TipeOut(n);
		TipeOut2(Obj, n);
	}
	void TipeOut(int n){
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				cout << '\n' << "  ";
			}
				cout << "  " << i + 1;
		}
	}
	void TipeOut2(bitGraph& Obj,int n){
		for (int i = 0; i < n; i++)
		{
			cout << '\n' << " " << i + 1 << " |";
			for (int j = 0; j < n; j++) {
				if (Obj.Value[i][j] == -1)
				{
					cout << " " << '-' << " ";
				}
				else {
					cout << " " << Obj.Value[i][j] << " ";
					}
			}
		}
	};
};