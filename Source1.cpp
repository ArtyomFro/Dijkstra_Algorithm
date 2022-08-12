#include "Header1.h"

bitGraph::bitGraph(int n)
{
	Value = new int* [RebN = n];
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

void bitGraph::AddReb(int from, int to,int value) 
{
	if (from < 0 || from >= RebN || to < 0 || to >= RebN)
	{
		return;
	}
		Value[from][to] = value;
	
}

void bitGraph::Zapoln1(int Reb, int n)
{
	for (int i = 0; i < Reb; i++)
	{
		from = rand() % n;
		to = rand() % n;
		value = rand() % 10;
		if (Value[from][to] == -1)
		{
			AddReb(from, to, value);
		}else {
			i--;
		}
	}
}

void bitGraph::Zapoln2(int Reb, int n)
{
	for (int i = 0; i < Reb; i++)
	{
		cout << "Введите начало дуги(от 1) " << endl;
		cin >> from;
		from= from-1;
		cout << "Введите конец дуги(от 1) " << endl;
		cin >> to;
		to= to-1;
		cout << "Введите стоимость прохода по этой дуге(от 0 до 9)" << endl;
		cin >> value;
		if (Value[from][to] == -1)
		{
			AddReb(from, to, value);
		}
		else {
			i--;
			cout << "Дуга уже существует" << endl;
		}
	}
}

void bitGraph::Show(int From, int to)
{
	if (!minNum.empty())
	{
		cout << "Вес минимального пути = " << Dist[to] << endl;
		cout << "Кратчайший путь из веришны " << From + 1 << " в вершину " << to + 1 << endl;
		cout<< From + 1;
		for (int i = 0; i = minNum.size(); i++)
		{
			cout << "->";
			cout << minNum.back()+1;
			minNum.pop_back();
		}
		cout << "->" <<to + 1;
	}else {
		if (Dist[to] != 100000)
		{
			cout << "Вес минимального пути = " << Dist[to] << endl;
			cout << "Кратчайший путь из веришны " << From + 1 << " в вершину " << to + 1 << endl;
			cout << From + 1;
			cout << "->" << to + 1;
		}
		else {
			cout << "Путь из вершины " << From + 1 << " в вершину " << to + 1 << " не существует" << endl;
		}
	}
}
void bitGraph::ShowTable(int n)
{
	if (n < 21) { 
		cout << '\n' << "Матрица смежности" << endl;
		cout << "  " << "  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20";
		cout << '\n' << "   -----------------------------------------------------------------";
		for (i = 0; i < n; i++)
		{
			cout << '\n' << " " << i + 1 << " |";
			for (j = 0; j < n; j++)
				if(Value[i][j] == -1)
				{
					cout << " " << '-' << " ";
				}
				else {
					cout << " " << Value[i][j] << " ";
				}
		}
	}
}

int bitGraph::Obhod(int from, int to,int n)
{
	int min1=0, min2=0;
	for (int i = 0; i < n; i++)
	{
		Parent[i] = i;
	    Dist[i] = 100000;
	}
	Dist[from] = 0;
	for (int i = 0; i != n; i++)
	{
		int minV = 100000;
		for (int k = 0; k < n; k++)
		{
			if ((minV > Dist[k]) & (!visited[k]))
			{
				minV = Dist[k];
				min1 = i;
				min2 = k;
			}
		}
		visited[min2] = true;
		for (int k = 0; k < n; k++)
		{
			if ((Value[min2][k] != (-1)) & (Dist[k] > (Dist[min2] + Value[min2][k])))
			{
				Dist[k] = Dist[min2] + Value[min2][k];
				Parent[k] = min2;
			}
		}
	}
	if (Dist[to] == 100000)
	{
		return 0;
	}
 	int parnode = Parent[to];
	while (parnode != StartFrom)
	{
		minNum.push_back(parnode);
		parnode = Parent[parnode];
	}
}

