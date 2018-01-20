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
	friend void get(istream& is,date& dt);
	friend void put(ostream& os,const date& dt);
};

void get(istream& is,date& dt) {
	is >> dt.d;
}

void put(ostream& os,const date& dt) {
	os << dt.d << endl;
}

int main(void)
{
	date dt;
	dt.init();
	get(cin,dt);
	put(cout,dt);

	return 0;
}