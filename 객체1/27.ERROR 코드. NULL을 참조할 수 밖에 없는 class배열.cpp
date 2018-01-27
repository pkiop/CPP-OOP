#include <iostream>

using namespace std;

class myclass {
	int* pa;
public:
	myclass(void) { pa = NULL; }
	myclass(int v) { pa = new int[v]; }
	~myclass(void) {
		if (pa != NULL)
			delete pa;
		cout << "destructor" << endl;
	}
	void set_array(void) {
		for (int i = 0; i < 3; ++i) {
			pa[i] = 3;
		}
	}
	int get_val(void) { return pa[0]; }
};

int main(void)
{
	myclass* p;
	p = new myclass[3];
	for (int i = 0; i < 3; ++i) {
		p[i].set_array();
	}
	cout << p->get_val() << endl;
	cout << p[0].get_val() << endl;
	cout << p[1].get_val() << endl;
	cout << p[2].get_val() << endl;
	delete[] p;
	return 0;
}