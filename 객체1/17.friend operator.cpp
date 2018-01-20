#include <iostream>
using namespace std;
class date {
	int d, m, y;
public:
	friend void operator>>(istream& is, date* dt) {
		is >> dt->d;
	}
	friend void operator<<(ostream& os, const date* dt) {
		os << dt->d << endl;
	}
};
int main(void)
{
	date dt;
	operator>>(cin, &dt);
	operator<<(cout, &dt);
	cin >> &dt;
	cout << &dt;
	cin >> &dt;
	cout << &dt;
	return 0;
}
