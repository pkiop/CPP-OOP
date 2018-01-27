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
	int* get_val(void) { return pa; }
};

int main(void)
{
	myclass* p;
	p = new myclass(3);

	cout << p->get_val() << endl;
	delete p;
	return 0;
}