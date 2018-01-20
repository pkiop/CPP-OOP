#include <iostream>

using namespace std;

class vector {
	int x, y;
public:
	vector(int _x, int _y) :x(_x), y(_y) {}
	vector(const vector& vc) :x(vc.x),y(vc.y) {}
public:
	void print(void) const {
		cout << x << ' ' << y << endl;
	}
};

int main(void)
{
	vector a(1, 2);
	vector b(a);
	vector c = a;

	a.print();
	b.print();
	c.print();
	return 0;
}