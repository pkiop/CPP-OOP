#include <iostream>

using namespace std;

typedef int data_t;

class darray {
	size_t len; // 32bits --> unsigned int,
				// 64bits --> unsigned long long
	data_t* ep;
public:
	darray(void) :len(0), ep(NULL) {}
	darray(int ll) :len(ll), ep(new data_t[ll]) {}
	darray(const darray& da):len(da.len),ep(new data_t[da.len]) {
		for (int i = 0; i < len; ++i)
		{
			ep[i] = da.at(i);
		}
	}

	~darray(void)
	{
		if (ep != NULL)
			delete[] ep;
		len = 0;
	}

	const data_t at(const size_t index) const {
		return ep[index];
	}

	void assign(const data_t *p) const {
		for (int i = 0; i < len; ++i)
			ep[i] = p[i];
	}

	friend ostream& operator << (ostream& os, const darray& da) {
		for (int i = 0; i < da.len; ++i)
			os << da.at(i) << ' ';
		return os;
	}
};

int main(void)
{
	darray d1(3);
	const int a[3] = { 1,2,3 };
	d1.assign(a);
	cout << d1 << endl;

	darray d2(d1);
	cout << d2 << endl;

	return 0;
} 
