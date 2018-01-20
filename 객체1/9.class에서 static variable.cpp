#include <iostream>
using namespace std;
class myclass {
	int id;
	static int num_obj; //declaration
public:
	void assign_id(void) { id = num_obj++; }
	int get_id(void) const { return id; };
};
int myclass::num_obj = 0;//definition and intialization
int main(void)
{
	myclass mc1, mc2;
	cout << sizeof(mc1) << ' ';
	cout << sizeof(mc2) << endl;
	mc1.assign_id();
	mc2.assign_id();
	cout << mc1.get_id() << ' ';
	cout << mc2.get_id() << endl;
	return 0;
}
