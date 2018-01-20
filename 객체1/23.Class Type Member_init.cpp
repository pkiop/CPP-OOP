#include <iostream>

using namespace std;

class vector {
	int x, y;
public:
	vector(int _x, int _y) :x(_x), y(_y) {}
};

class vec3 {
	vector vc2;
	int z;
public:
	vec3(int _x,int _y,int _z):vc2(_x,_y),z(_z){}
};

int main(void)
{
	vec3 a(1, 2, 3);
	
	return 0;
}