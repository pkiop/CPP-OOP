#include <iostream>

using namespace std;

struct date {
	int d, m, y;
	void add_day(int n);
	int day(void) const;
};

void date::add_day(int n)
{
	this->d += n;
}

int date::day(void) const
{
	return this->d;
}

int main(void)
{
	date dt = { 25,1,1991 };
	const date cdt = { 20,2,99 };

	dt.add_day(3);
	cout << dt.day() << endl;
	//cdt.add_day(2);
	cout << cdt.day() << endl;
	return 0;
}