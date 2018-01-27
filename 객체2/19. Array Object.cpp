#include <iostream>
using namespace std;
class array_obj {
	int size;
public:
	array_obj(int s) : size(s) {}
	int operator[](int i) const {
		return i % size;
	}
};
int main(void)
{
	array_obj a(5);
	for (int i = 0; i < 10; ++i)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}
