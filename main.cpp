#include <ctime>
#include <iostream>
#include <vector>
#include "Header.h"
#include "Show.cpp"
#include "Choice.cpp"
#include "Zapoln.cpp"
#include "Obhod.cpp"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Hig hig;
	Reb reb;
	Start start;
	Finish finish;
	int n = hig.Choice();
	int Reb = reb.Choice();
	Obhod obhod;
	bitGraph N(n);
	ShowPath showPath;
	ShowTable showTable;
	Zapoln zap;
	zap.zapoln(N,Reb, n);
	showTable.Table(N,n);
	int Start = start.Choice();
	int Finish = finish.Choice();
	N.StartFrom = Start;
	obhod.obhod(N,Start,Finish,n);
	showPath.Path(N,Start,Finish);
	system("Pause");
	return 0;
}