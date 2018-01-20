#include <iostream>

using namespace std;

struct date {
	int d, m, y;

	date(void);
	date(int dd);
	date(int dd, int mm);
	date(int dd, int mm, int yy);
};

date::date(void)
{
	d = 1;
	m = 1;
	y = 1991;
}

date::date(int dd) {
	d = dd;
	m = 1;
	y = 1991;
}

date::date(int dd, int mm) {
	d = dd;
	m = mm;
	y = 1991;
}

date::date(int dd, int mm, int yy)
{
	d = dd;
	m = mm;
	y = yy;
}

int main(void)
{
	date dt1;
	date dt2(20);
	date dt3(20, 2);
	date dt4(20, 2, 2010);
	return 0;
}