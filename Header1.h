#pragma once
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;
class bitGraph 
{
private:
	int** Value;
	int k = 0;
	int Dist[100];
	int Parent[100];
	bool visited[100];
	int RebN;
	int from;
	int to;
	int value;
	int j = 0;
	int i = 0;
	vector<int> minNum;
public:
	int StartFrom;
	bitGraph(int n);
	~bitGraph();
	int CountRib() const 
	{
		return RebN;
	}
	void AddReb(int from, int to,int value);
	void Zapoln1(int Reb, int n);
	void Zapoln2(int Reb, int n);
	int Obhod(int from, int to,int n);
	void Show(int form, int to);
	void ShowTable(int n);
};