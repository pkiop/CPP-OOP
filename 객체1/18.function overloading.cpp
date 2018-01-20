#include <iostream>

using namespace std;

struct date {
	int d, m, y;
	void init(void);
	void init(int dd);
	void init(int dd,int mm);
	void init(int dd,int mm,int yy);
};

void date::init(void) {
	d = 1;
	m = 1;
	y = 1991;
}

void date::init(int dd) {
	d = dd;
	m = 1;
	y = 1991;
}
void date::init(int dd,int mm) {
	d = dd;
	m = mm;
	y = 1991;
}
void date::init(int dd,int mm,int yy) {
	d = dd;
	m = mm;
	y = yy;
}
int main(void)
{
	date dt1,dt2,dt3,dt4;
	dt1.init();
	dt2.init(3);
	dt3.init(3, 4);
	dt4.init(3, 5, 2018);
	cout << dt1.d << ' ' << dt1.m << ' ' << dt1.y << endl;
	cout << dt2.d << ' ' << dt2.m << ' ' << dt2.y << endl;
	cout << dt3.d << ' ' << dt3.m << ' ' << dt3.y << endl;
	cout << dt4.d << ' ' << dt4.m << ' ' << dt4.y << endl;
	return 0;
}

