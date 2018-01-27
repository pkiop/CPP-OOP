#include <iostream>
using namespace std;
template <typename T>
inline T max_t(T a, T b)
{
	return a > b ? a : b;
}
int main(void)
{
	int ia = 2, ib = 3;
	double da = 2.1, db = 3.1;
	cout << max_t(ia, ib) << endl;
	cout << max_t(da, db) << endl;
	return 0;
}
