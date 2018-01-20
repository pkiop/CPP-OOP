#include <iostream>
using namespace std;
struct date {
	int d, m, y;
	date(int dd, int mm, int yy);
};
date::date(int dd, int mm, int yy)
{
	d = dd;
	m = mm;
	y = yy;
}
int main(void)
{
	date dt(20, 2, 2010);
	return 0;
}
