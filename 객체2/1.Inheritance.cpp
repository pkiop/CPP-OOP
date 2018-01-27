#include <iostream>

using namespace std;

struct people {
	int id;
	char name[4];
};

struct student : people {
	int s_id;
	int grade;
};

struct professor : people {
	int p_id;
};

int main(void)
{
	people p;
	student s;
	professor f;

	cout << sizeof(p) << endl;
	cout << sizeof(s) << endl;
	cout << sizeof(f) << endl;

	return 0;
}