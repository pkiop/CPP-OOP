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
	static void g(myclass& mc) { //���ڷ� �޴� ���� �翬�� ����
		mc.value = 3;
		cout << mc.value << endl;
	}
};
int main(void)
{
	myclass mc;
	myclass::g(mc); //�� �ٶ���
	mc.g(mc);       //��¿ �� ���
	return 0;
}

//============================ =

//static function�� c�� ��ġ��

//void f(void) {

//}

//�̷��� ���̴�. == > this �� ����.
