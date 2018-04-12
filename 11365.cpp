#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	string text;
	while (getline(cin,text) && strcmp(text.c_str(),"END") != 0) {		
		std::reverse(text.begin(), text.end());
		cout << text << "\n";
	}
	return 0;
}