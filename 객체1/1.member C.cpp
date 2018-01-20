//C language

#include <iostream>

using namespace std;

struct date {
	int d, m, y;
};

void add_day(struct date* th, int n)
{
	th->d += n;
}

int main(void)
{
	struct date dt = { 25,1,1991 };
	cout << dt.d << endl;
	add_day(&dt, 3);
	cout << dt.d << endl;
	return 0;
}