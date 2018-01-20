#include <iostream>

using namespace std;

class myclass {
	int a;
protected:
	void bf(void) { a = 2; }
public:
	int c;
	friend void init(myclass& rg);
};

void init(myclass& rg)
{
	rg.a = 11;
	rg.bf();
	rg.c = 33;
};

int main(void)
{
	myclass my;

	init(my);
	return 0;
}