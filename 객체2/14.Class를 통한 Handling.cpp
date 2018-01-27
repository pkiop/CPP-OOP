#include <iostream>

using namespace std;

struct e1{};
class e2{};
int main(void)
{
	int v;

	try {
		cin >> v;
		if (v == 1) throw e1();
		if (v == 2) throw e2();
		cout << "In try." << endl;
	}
	catch (e1) {
		cout << "e1" << endl;
	}
	catch (e2) {
		cout << "e2" << endl;
	}
	cout << "Try-catch end" << endl;
	return 0;
}