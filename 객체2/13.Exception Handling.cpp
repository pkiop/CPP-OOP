#include <iostream>

using namespace std;

void g(int v)
{
	if (v == 1 || v == 2) throw v;
}

void f(int v)
{
	g(v);
	if (v == 3) throw 3.0;
}

int main(void)
{
	int v;
	
	try {
		cin >> v;
		f(v);
		if (v == 4) throw '4';
		if (v == 5) throw '5';
		cout << "No Exception";
		cout << v << endl;
	}
	catch (int e) {
		cerr << "Exception: int(" << e << ")" << endl;
	}
	catch (double) {// catch�� ���� ���� ���� �Ÿ� �׳� Ÿ�Ը� ���´�.
		cerr << "Exception: double" << endl;
	}
	catch (char c) {
		cerr << "Exception: char(" << c << ")" << endl;
	}
	cout << "Try-catch end." << endl;
	return 0;
}