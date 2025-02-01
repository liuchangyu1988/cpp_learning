#include <iostream>
#include <sstream>
#include <algorithm>

int main()
{
	using namespace std;
	std::cout<<"Hello World"<< endl;

	string s = "test1, test3, test5";
	stringstream ss(s);
	string output;
	while (getline(ss, output, ',')) {
		output.erase(std::remove_if(output.begin(), output.end(), [](char a) {
			return a == ' ';
		}), output.end());
		cout << output << endl;
	}

	return 0;
}
