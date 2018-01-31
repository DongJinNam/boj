#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001] = { 0 };

int getMax(string s1, string s2) {
	int max = 0;
	for (int i = 1; i <= s2.length(); i++) {
		for (int j = 1; j <= s1.length(); j++) {
			if (s1[j - 1] == s2[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			}
			max = dp[i][j] > max ? dp[i][j] : max;
		}
	}
	return max;
}

int main() {
	int result = 0;
	string s1, s2;
	cin >> s1 >> s2;	
	
	if (s1.length() > s2.length())
		result = getMax(s1, s2);
	else
		result = getMax(s2, s1);

	cout << result << "\n";
	return 0;
}