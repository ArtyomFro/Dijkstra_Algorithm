#include "Header.h"

struct ZapolnInteface {
	virtual ~ZapolnInteface() = default;
	virtual void Zapoln(bitGraph& Obj, int Reb, int n) = 0;
};

struct ZapolnRandom : ZapolnInteface{
	void Zapoln(bitGraph& Obj, int Reb, int n) override
	{
		srand(time(NULL));
		for (int i = 0; i < Reb; i++)
		{
			Obj.from = rand() % n;
			Obj.to = rand() % n;
			Obj.value = rand() % 10;
			if (Obj.Value[Obj.from][Obj.to] == -1)
			{
				if (Obj.from < 0 || Obj.from >= Obj.RebN || Obj.to < 0 || Obj.to >= Obj.RebN)
				{
					return;
				}
				Obj.Value[Obj.from][Obj.to] = Obj.value;
			}
			else {
				i--;
			}
		}
	}
};

struct ZapolnSam : ZapolnInteface {
	void Zapoln(bitGraph& Obj,int Reb, int n) override
	{
		for (int i = 0; i < Reb; i++)
		{
			while (1) {
				cout << "¬ведите начало дуги(от 1) " << endl;
				cin >> Obj.from;
				Obj.from = Obj.from - 1;
				if (Obj.from < n) {
					break;
				}
			}
			while(1){
				cout << "¬ведите конец дуги(от 1) " << endl;
				cin >> Obj.to;
				Obj.to = Obj.to - 1;
				if (Obj.to < n) {
					break;
				}
			}
				cout << "¬ведите стоимость прохода по этой дуге(от 0 до 9)" << endl;
				while (1) {
					cin >> Obj.value;
					if (Obj.value < 10 && Obj.value >= 0) {
						break;
					}
				}
			
			if (Obj.Value[Obj.from][Obj.to] == -1)
			{
				if (Obj.from < 0 || Obj.from >= Obj.RebN || Obj.to < 0 || Obj.to >= Obj.RebN)
				{
					return;
				}
				Obj.Value[Obj.from][Obj.to] = Obj.value;
			}
			else {
				i--;
				cout << "ƒуга уже существует" << endl;
			}
		}
	}
};

struct Zapoln {
	void zapoln(bitGraph& ObjMain, int reb, int n) {
		bool klav;
		ZapolnRandom Random;
		ZapolnSam Sam;
		cout << "’отите ввести граф c клавиатуры?(1/0)" << endl;
		cin >> klav;
		switch (klav)
		{
		case 0:
		{
			Random.Zapoln(ObjMain, reb, n);
			break;
		}
		case 1:
		{
			Sam.Zapoln(ObjMain, reb, n);
			break;
		}
		}
	}
};