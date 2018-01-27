#include <iostream>

using namespace std;

struct base1 {
	int x;
};

struct base2 {
	float y1, y2;
};

struct derived : public base1, public base2 {
	char z[4];
};

int main(void)
{
	derived d;
	base1* p1 = &d;
	base2* p2 = &d;
	derived* p3 = &d;

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	return 0;
}