#include <iostream>

using namespace std;

struct vec1 {
	int id, x;
	vec1(int _id,int _x):id(_id),x(_x){}
};

struct vec2 : vec1 {
	int id, y;
	vec2(int bid,int _id,int _x,int _y):vec1(bid,_x),id(_id),y(_y){}

	int vid(void) const {
		if (id > 0) return id;
		return vec1::id;
	}
};

int main(void)
{
	vec2 v2(1, 11, 333, 444);
	cout << v2.vid() << endl;
	vec2 v3(1, 0, 333, 444);
	cout << v3.vid() << endl;
	return 0;
}