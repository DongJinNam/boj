#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int arr[3];
	string s;
	cin >> arr[0] >> arr[1] >> arr[2];
	cin >> s;
	std::sort(arr, arr + 3);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'A') {
			cout << arr[0];
		}
		else if (s[i] == 'B') {
			cout << arr[1];
		}
		else {
			cout << arr[2];
		}
		if (i == s.length() - 1) cout << endl;
		else cout << " ";
	}
	return 0;
}