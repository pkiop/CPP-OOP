#include <iostream>

using namespace std;

struct date {
	int d, m, y;
	date(int dd, int mm, int yy);
	~date(void);
};

date::date(int dd, int mm, int yy)
{
	this->d = dd;
	this->m = mm;
	this->y = yy;
	cout << "constructor: " << y << endl;
}

date::~date(void)
{
	cout << "destructor: " << y << endl;
}

int main(void) {
	date dt1(1, 1, 2015);
	{
		date dt2(1, 1, 2016);
	}
	return 0;
}