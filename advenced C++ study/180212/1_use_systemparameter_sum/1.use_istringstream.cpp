#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
	int sum = 0;
	
	for (int i = 1; i<argc; ++i) {
		istringstream is(argv[i]);
		int temp;
		is >> temp;
		sum += temp;
	}
	cout << sum << endl;
	return 0;
}