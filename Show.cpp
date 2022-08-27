#include "Header.h"

struct ShowPath {
	void Path(bitGraph& Obj, int From, int to)
	{
		if (!Obj.minNum.empty())
		{
			cout << "��� ������������ ���� = " << Obj.Dist[to] << endl;
			cout << "���������� ���� �� ������� " << From + 1 << " � ������� " << to + 1 << endl;
			cout << From + 1;
			for (int i = 0; i = Obj.minNum.size(); i++)
			{
				cout << "->";
				cout << Obj.minNum.back() + 1;
				Obj.minNum.pop_back();
			}
			cout << "->" << to + 1;
		}
		else {
			if (Obj.Dist[to] != 100000)
			{
				cout << "��� ������������ ���� = " << Obj.Dist[to] << endl;
				cout << "���������� ���� �� ������� " << From + 1 << " � ������� " << to + 1 << endl;
				cout << From + 1;
				cout << "->" << to + 1;
			}
			else {
				cout << "���� �� ������� " << From + 1 << " � ������� " << to + 1 << " �� ����������" << endl;
			}
		}
		cout << endl;
	}
};

struct ShowTable {
	void Table(bitGraph& Obj,int n)
	{
			cout << '\n' << "������� ���������" << endl;
			for (int i = 0; i < n; i++) {
				if (i == 0) {
					cout << '\n' << "  ";
				}
				cout << "  " << i+1;
			}

			for (int i = 0; i < n; i++)
			{
				cout << '\n' << " " << i + 1 << " |";
				for (int j = 0; j < n; j++)
					if (Obj.Value[i][j] == -1)
					{
						cout << " " << '-' << " ";
					}
					else {
						cout << " " << Obj.Value[i][j] << " ";
					}
			
		}
			cout << endl;
	}
};