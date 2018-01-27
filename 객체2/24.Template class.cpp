#include <iostream>
using namespace std;
template <typename T>
class accum {
	T v;
public:
	accum(T _v) :v(_v) {}
	void reset(T _v) {
		v = _v;
	}
	accum& operator+=(T _v) {
		v += _v;
		return *this;
	}
	accum& operator*=(T _v) {
		v *= _v;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const accum& ac) {
		return os << ac.v;
	}
};
int main(void)
{
	accum<int> iacc(0);
	iacc += 1;
	iacc += 2;
	iacc += 3;
	cout << iacc << endl;
	iacc.reset(0);
	iacc += 11;
	iacc += 22;
	iacc += 33;
	cout << iacc << endl;
	accum<double> dacc(1.0);
	dacc *= 1.0;
	dacc *= 2.0;
	dacc *= 3.0;
	dacc *= 4.0;
	cout << dacc << endl;
	return 0;
}
