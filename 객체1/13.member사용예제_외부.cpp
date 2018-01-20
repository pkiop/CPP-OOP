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
	void get(istream& is);
	void put(ostream& os) const;
};

void date::get(istream& is) {
	is >> d;
}

void date::put(ostream& os) const {
	os << d << endl;
}

int main(void)
{
	date dt;
	dt.init();
	dt.get(cin);
	dt.put(cout);

	return 0;
}