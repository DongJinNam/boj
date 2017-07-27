#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	string s;
	locale loc;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {			
			cout << std::tolower(s[i], loc);
		}
		else {
			cout << std::toupper(s[i], loc);
		}		
	}
	cout << endl;
	return 0;
}