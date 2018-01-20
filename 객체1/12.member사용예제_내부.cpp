#include <iostream>

using namespace std;

class date{
	int d, m, y;
public:
	void init(void) {
		d = 0;
		m = 0;
		y = 0;
	}
	void add_day(int n) {
		this->d += n;
	}
	int day(void) const {
		return d;
	}
};

int main(void)
{
	date dt;
	dt.init();
	cout << dt.day() << endl;
	dt.add_day(3);
	cout << dt.day() << endl;

	return 0;
}