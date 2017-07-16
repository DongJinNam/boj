#include <iostream>
#include <string>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	string s1, s2;
	int tc;
	int h_dis = 0;

	cin >> tc;
	while (tc--) {
		cin >> s1;
		cin >> s2;
		h_dis = 0;
		for (int i = 0; i < s1.length(); i++) {
			if (s1.at(i) != s2.at(i)) h_dis++;
		}
		cout << "Hamming distance is " << h_dis << "." << endl;
	}	
	return 0;
}
