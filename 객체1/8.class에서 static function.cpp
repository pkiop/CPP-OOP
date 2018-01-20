#include <iostream>
using namespace std;
class myclass {
	int value;
public:
	static void f(void) {
		//value = 3;
		//this->value = 3;
		//myclass::value = 3;
	}
	static void g(myclass& mc) { //인자로 받는 것은 당연히 가능
		mc.value = 3;
		cout << mc.value << endl;
	}
};
int main(void)
{
	myclass mc;
	myclass::g(mc); //더 바람직
	mc.g(mc);       //어쩔 수 없어서
	return 0;
}

//============================ =

//static function을 c로 고치면

//void f(void) {

//}

//이렇게 끝이다. == > this 가 없다.
