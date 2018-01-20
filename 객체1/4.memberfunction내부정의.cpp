//C++ language
//Member 함수는 그 Class의 Method 결정
#include <iostream>
using namespace std;
struct date {
	int d, m, y;
	void add_day(int n)
	{
		d += n;
		this->d += n;
		date::d += n;
	}
};
int main(void)
{
	struct date dt = { 25,1,1991 };
	cout << dt.d << endl;
	dt.add_day(3);
	cout << dt.d << endl;
	return 0;
}
