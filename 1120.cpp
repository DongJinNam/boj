#include <iostream>
#include <string>

using namespace std;

int dp[51];

int main() {
	std::ios::sync_with_stdio(false);

	string a, b;
	int i, j;
	int ans = 100;

	cin >> a >> b;	
	if (a.length() == b.length()) {
		ans = 0;
		for (int i = 0; i < b.length(); i++) {
			if (a[i] != b[i]) ans++;
		}
	}
	else {
		for (i = 0; i <= b.length() - a.length(); i++) {
			for (j = 0; j < a.length(); j++) {
				if (a[j] != b[i + j]) dp[i]++;
			}
		}	
		for (i = 0; i <= b.length() - a.length(); i++) {
			if (dp[i] < ans) ans = dp[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}