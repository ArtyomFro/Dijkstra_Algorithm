#pragma once
#include <ctime>
#include <iostream>
#include <vector>


using namespace std;
class bitGraph
{
public:
	int** Value;
	int Dist[1000];
	int Parent[1000];
	int RebN;
	int from;
	int to;
	int value;
	int StartFrom;
	bool visited[1000];
	vector<int> minNum;
	bitGraph(int n);
	~bitGraph();
};


