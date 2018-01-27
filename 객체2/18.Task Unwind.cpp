#include <iostream>

using namespace std;

void f(int a, int b)
{
	double c;
	throw 7;
}

void g(int x)
{
	double a[4];
	f(x + 1, x + 2);
}

int main(void)
{
	int x;
	try {
		g(3);
	}
	catch (int e) {
		cout << "int type: " << e << endl;
	}
	return 0;
}