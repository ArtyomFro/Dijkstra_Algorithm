#include "Header.h"

struct ChoiceInterface {
	virtual ~ChoiceInterface() = default;
	virtual int Choice() = 0;
};

struct Hig : ChoiceInterface {
	int Choice() override{
		int n;
		cout << "¬ведите количество вершин в вашем графе" << endl;
		cin >> n;
		return n;
	}
};

struct Reb : ChoiceInterface {
	int Choice() override {
		int reb;
		cout << "¬ведите количество ребер в вашем графе " << endl;
		cin >> reb;
		return reb;
	}
};

struct Start : ChoiceInterface {
	int Choice() override {
		int start;
		cout << "¬ведите начальную точку обхода(ќт 1)" << endl;
		cin >> start;
		start = start - 1;
		return start;
	}
};
struct Finish : ChoiceInterface{
	int Choice() {
		int finish;
		cout << "¬ведите конечную точку обхода(ќт 1)" << endl;
		cin >> finish;
		finish = finish - 1;
		return finish;
	}
};