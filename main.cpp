#include <ctime>
#include <iostream>
#include <vector>
using namespace std;
#include "Header1.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	bool klav;
	int n, reb;
	int Start;
	int Finish;
	cout << "������� ���������� ������ � ����� �����" << endl;
	cin >> n;
	cout << "������� ���������� ����� � ����� ����� " << endl;
	cin >> reb;
	bitGraph N(n);
	cout << "������ ������ ���� c ����������?(1/0)" << endl;
	cin >> klav;
	switch (klav)
	{
	case 0:
	{
		N.Zapoln1(reb, n);
		break;
	}
	case 1:
	{
		N.Zapoln2(reb, n);
		break;
	}
	}
	N.ShowTable(n);
	cout << endl;
	cout << "������� ��������� ����� ������(�� 1)" << endl;
	cin >> Start;
	Start = Start - 1;
	N.StartFrom = Start;
	cout << "������� �������� ����� ������(�� 1)" << endl;
	cin >> Finish;
	Finish = Finish - 1;
	N.Obhod(Start,Finish,n);
	N.Show(Start,Finish);
	return 0;
}