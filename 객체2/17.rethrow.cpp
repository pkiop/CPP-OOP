#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	try {
		try {
			if (n % 2 == 0) throw n;
			cout << "no exception" << endl;
		}
		catch (int a) {
			cout << "int type" << a << endl;
			if (a % 3 == 0) throw;
		}
	}
	catch (int b){
		cout << "int type" << b << endl;
    }
	return 0;
}