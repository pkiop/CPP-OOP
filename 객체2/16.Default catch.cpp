#include <iostream>

using namespace std;

int main()
{
	int n;

	cin >> n;
	try {
		if (n == 1)
			throw 3;
		if (n == 2)
			throw 3.4;
		cout << "no exception." << endl;
	}
	catch (int) {
		cout << "int type" << endl;
	}
	/*catch (...) {
		cout << "default" << endl;
	}*/

	return 0;
}