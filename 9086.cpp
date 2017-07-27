#include <iostream>
#include <string>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		int len;
		cin >> s;
		len = s.length();
		if (len == 1) 
			cout << s[0] << s[0] << endl;		
		else 
			cout << s[0] << s[len-1] << endl;		
	}
	return 0;
}