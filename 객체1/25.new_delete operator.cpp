#include <iostream>

using namespace std;

class myclass {
	int value;
public:
	myclass(int v) { value = v; }
	int get_val(void) { return value; }
};

int main(void)
{
	myclass* p;
	p = new myclass(3);

	cout << p->get_val() << endl;
	delete p;
	return 0;
}