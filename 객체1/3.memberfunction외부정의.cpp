//C++ language
//Member �Լ��� �� Class�� Method ����
#include <iostream>
using namespace std;
struct date {
	int d, m, y;
	void add_day(int n); //struct date* this�� ù��° �����ε� �����Ǿ���.
};
void date::add_day(int n) //struct date* this�� �����ǰ� date::���� �ٲ����.
{
	this->d += n; //default �� �� 
	d += n;       //�̷��� ��밡��
	date::d += n; //�̷��� ��밡��
}
int main(void)
{
	struct date dt = { 25,1,1991 };
	cout << dt.d << endl;
	dt.add_day(3); //ù��° ���ڷ� ���� struct date*�� Ÿ���� ���� �ϴµ� 
				   //&dt�� dt.���� �ٲ����.
	cout << dt.d << endl;
	return 0;
}
