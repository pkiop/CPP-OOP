#include <iostream>

using namespace std;

class base {
public:
	virtual int f(void) const = 0;
	virtual int g(void) const = 0;
};

class derived1: public base {
public:
	int f(void) const { return 0; }
};

class derived2 : public base {
public:
	int f(void) const { return 0; }
	int g(void) const { return 1; }
};

int main(void)
{
	base a;
	derived1 b;
	derived2 c;
	return 0;
}