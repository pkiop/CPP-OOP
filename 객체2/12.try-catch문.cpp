#include <iostream>

using namespace std;

int main(void)
{
	int v;
	
	try {
		cin >> v;
		if (v == 1) throw 5;
		cout << "In try" << endl;
	}
	catch (int a) {
		cout << "In catch: " << a << endl;
	}
	cout << "Try-catch end." << endl;
}