#include <iostream>

using namespace std;

class myclass {
	int a;
protected:
	void bf(void) { a = 2; }
public:
	int c;
	friend class myclass2;
};

class myclass2 {
public:
	void f(myclass& rg) {
		rg.a = 11;
		rg.bf();
		rg.c = 33;
	}
};
int main(void)
{
	myclass my;
	myclass2 my2;

	my2.f(my);
	return 0;
}