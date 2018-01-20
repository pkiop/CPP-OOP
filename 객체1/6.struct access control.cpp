#include <iostream>

using namespace std;

struct myclass {
public:
	int a;
private:
	int b;
};

int main(void)
{
	myclass mc;
	mc.a = 1;
	//mc.b = 2;
	return 0;
}