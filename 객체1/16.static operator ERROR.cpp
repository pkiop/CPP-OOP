#include <iostream>

using namespace std;

class date {
	int d, m, y;
public:
	static void operator>>(istream& is, date* dt) {
		is >> dt->d;
	}
	static void operator<<(ostream& os, const date* dt) {
		os << dt->d << endl;
	}
};

int main(void)
{
	date dt;
	date::operator>>(cin, &dt);
	date::operator<<(cout, &dt);
	return 0;
}