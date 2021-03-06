#include <iostream>

using namespace std;



template<typename T>
class farray { //fixed array
	typedef T data_t;
	static const size_t alen = 5;
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
	data_t& operator[](size_t index) {
		return a[index];
	}
	data_t operator[](const size_t index) const {
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

struct data_t {
	double x;
	int y;
	friend ostream& operator<<(ostream& os, const data_t& dt) {
		os << "(" << dt.x << ' ' << dt.y << ")" << ' ';
		return os;
	}
};


int main(void) {
	data_t v[] = { {1.1,11 }, {2.2,22},{ 3.3,33}, {4.4,44}};
	data_t v1 = { 9.9,99 }, v2 = { 1.1,11 };
	size_t vlen = sizeof(v) / sizeof(*v);
	farray<data_t> a;
	farray<data_t> b(v1);
	farray<data_t> c(v, 2);
	farray<data_t> d(v, vlen);
	const farray<data_t> e(d);

	cout << a << endl;
	for (size_t i = 0; i < a.size(); ++i)
		a[i] = v2;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	for (size_t i = 0; i < e.size(); ++i)
		cout << e[i] << ' ';
	cout << endl;
	return 0;
}