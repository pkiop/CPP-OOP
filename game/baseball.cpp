#include <iostream>
#include <time.h>

using namespace std;

class bbg {
	int a, b, c;
	int cnt;
public:
	bbg(void) : a(rand() % 10), cnt(0) {
		do {
			b = rand() % 10;
		} while (a == b);
		do {
			c = rand() % 10;
		} while (a == b || b == c);
		cout << a << ' ' << b << ' ' << c << endl;
	}
	bbg(int _a, int _b, int _c) : a(_a), b(_b), c(_c), cnt(0) {}
	
	bool mdrs(int x,int y,int z) {
		int st = 0, ba = 0, out = 3;
		cnt++;
		if (x == a) {
			st++;
			out--;
		}
		else if (x==y || x==z){
			ba++;
			out--;
		}
		if (y == b) {
			st++;
			out--;
		}
		else if (y == x || x == z) {
			ba++;
			out--;
		}
		if (z == c) {
			st++;
			out--;
		}
		else if (z == y || z == x) {
			ba++;
			out--;
		}
		cout << "S B O" << endl;
		cout << st << ' ' << ba << ' ' << out << endl;
		return vic(st);
	}
	bool vic(int st) {
		if (st == 3) {
			cout << cnt << "번 만에 승리하였습니다. " << endl;
			return false;
		}
	}
};

void process(void) {
	srand((unsigned int)time(0));
	bbg game;

	int x, y, z;
	do {
		cin >> x >> y >> z;
	} while (game.mdrs(x, y, z));
	return;
}

int main(void)
{
	process();
}