//C++ language
//Member 함수는 그 Class의 Method 결정
#include <iostream>
using namespace std;
struct date {
	int d, m, y;
	void add_day(int n); //struct date* this가 첫번째 인자인데 생략되었다.
};
void date::add_day(int n) //struct date* this가 생락되고 date::으로 바뀌었다.
{
	this->d += n; //default 한 값 
	d += n;       //이렇게 사용가능
	date::d += n; //이렇게 사용가능
}
int main(void)
{
	struct date dt = { 25,1,1991 };
	cout << dt.d << endl;
	dt.add_day(3); //첫번째 인자로 원래 struct date*의 타입이 들어가야 하는데 
				   //&dt가 dt.으로 바뀌었다.
	cout << dt.d << endl;
	return 0;
}
