#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void string_to_int(const string& s)
{
	istringstream iss(s);
	int a, b, c;
	iss >> a >> b >> c;
	cout << "a==" << a << endl;
	cout << "b==" << b << endl;
	cout << "c==" << c << endl;
}

string int_to_string(int a, int b, int c)
{
	ostringstream oss;
	oss << a << ' ';
	oss << b << ' ';
	oss << c;
	return oss.str();
}

int main(void)
{
	int a = 1;
	int b = 2;
	int c = 3;
	string s = int_to_string(a, b, c);
	cout << "s==" << s << endl;
	string_to_int(s);
	return 0;
}