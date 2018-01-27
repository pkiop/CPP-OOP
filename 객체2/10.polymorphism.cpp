#include <iostream>

using namespace std;

class vec2 {
	int x, y;
public:
	vec2(int _x, int _y) : x(_x), y(_y) {}
	virtual int sum(void) const { return x + y; }
};

class vec3 : public vec2 {
	int z;
public:
	vec3(int _x,int _y,int _z): vec2(_x,_y),z(_z){}
	int sum(void) const { return vec2::sum() + z; }
};

void print(vec2* a[], int num)
{
	for (int i = 0; i < num; ++i)
		cout << a[i]->sum() << endl;
}

int main(void) {
	vec2 v1(1, 2),v2(2,3),v5(3,4);
	vec3 v3(11, 22, 33), v4(22, 33, 44);
	vec2* a[] = { &v1,&v2,&v3,&v4,&v5 };

	print(a, sizeof(a) / sizeof(a[0]));
	return 0;
}