#include <iostream>

using namespace std;

struct ptr_sz {
	int* p;
	int sz;
public:
	ptr_sz(int* _p,int _sz): p(_p),sz(_sz) {}
};

int a1[5] = { 1,1,1,1,1 };

int main(void)
{
	int a2[4] = { 2,2,2,2 };
	try {
		static int a3[3] = { 3,3,3 };
		int a4[2] = { 4,4 };

		int len1 = sizeof(a1) / sizeof(*a1);
		int len2 = sizeof(a2) / sizeof(*a2);
		int len3 = sizeof(a3) / sizeof(*a3);
		int len4 = sizeof(a4) / sizeof(*a4);

		int v;
		cin >> v;
		if (a1[0] == v)
			throw ptr_sz(a1, len1);
		if (a2[0] == v)
			throw ptr_sz(a2, len2);
		if (a3[0] == v)
			throw ptr_sz(a3, len3);
		if (a4[0] == v)
			throw ptr_sz(a4, len4);
		cout << "In try." << endl;
	}
	catch (ptr_sz ps) {
		cout << "Catch: " << endl;
		for (int i = 0; i < ps.sz; ++i)
			cout << ps.p[i] << ' ';
		cout << endl;
	}
	cout << "Try-catch end." << endl;
	return 0;
}