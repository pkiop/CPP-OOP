#include <iostream>

using namespace std;

class vec2 {
	int x, y;
public:
	vec2(int _x, int _y) :x(_x),y(_y){}
	virtual int sum(void) const { return x + y; }
};

class vec3 :public vec2 {
	int z;
public:
	vec3(int _x,int _y,int _z):vec2(_x,_y),z(_z){}
	int sum(void) const { return vec2::sum() + z; }
};

int main(void)
{
	vec2 v2(11, 22);
	vec3 v3(111, 222, 333);
	vec2* p1 = &v2;
	vec2* p2 = &v3; // upcasting
	vec3* p3 = &v3;

	cout << p1->sum() << endl;
	cout << p2->sum() << endl;
	cout << p3->sum() << endl;
	return 0;
}