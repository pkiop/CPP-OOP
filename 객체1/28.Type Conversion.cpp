#include <iostream>

using namespace std;

class vector {
	int x, y;
public:
	vector(int _x,int _y): x(_x),y(_y){}
	vector(const vector& vc): x(vc.x),y(vc.y){}
public:
	operator int(void) const {
		return x + y;
	}
	void print(void) const {
		cout << x << ' ' << y;
	}
};

int main(void)
{
	vector v(1, 2);

	cout << int(v) << endl;
	cout << (int)v << endl;
	cout << v << endl;
	return 0;
}