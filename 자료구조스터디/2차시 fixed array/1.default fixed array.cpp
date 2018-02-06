#include <iostream>

using namespace std;

typedef double data_t;
const size_t alen = 5;

class farray { //fixed array
	data_t a[alen];
public:
	//constructors
	farray(void) {}

	farray(data_t* ep, size_t ln) {
		int i;
		for (i = 0; i < alen && i < ln; ++i) {
			a[i] = ep[i];
		}
	}

	farray(const farray& fa) {
		int i;
		for (i = 0; i < alen; ++i) {
			a[i] = fa.a[i];
		}
	}

	farray(data_t dt) {
		for (int i = 0; i < alen; ++i) {
			a[i] = dt;
		}
	}

	size_t size(void) const {
		return alen;
	}//return sequence length
	data_t& at(size_t index) {
		return a[index];
	}
	data_t at(const size_t index) const {
		return a[index];
	}


	//I/O operator
	friend ostream& operator << (ostream& os, const farray& fa) {
		for (int i = 0; i < fa.size(); ++i) {
			os << fa.a[i] << ' ';
		}
		return os;
	}
};

int main(void) {
	data_t v[] = { 1.1,2.2,3.3,4.4 };
	data_t v1 = 9.9, v2 = 1.1;
	size_t vlen = sizeof(v) / sizeof(*v);
	farray a;
	farray b(v1);
	farray c(v, 2);
	farray d(v, vlen);
	const farray e(d);

	cout << a << endl;
	for (size_t i = 0; i < a.size(); ++i)
		a.at(i) = v2;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	for (size_t i = 0; i < e.size(); ++i)
		cout << e.at(i) << ' ';
	cout << endl;
	return 0;
}