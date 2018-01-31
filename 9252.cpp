#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][1001] = { 0 };

// 기존의 LCS 문제와 동일
int getMax(string s1, string s2) {
	int max = 0;
	for (int i = 1; i <= s2.length(); i++) {
		for (int j = 1; j <= s1.length(); j++) {
			if (s1[j - 1] == s2[i - 1]) { // 두 문자열의 문자가 서로 일치한 경우
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else { // 문자가 서로 다른 경우
				dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			}
			max = dp[i][j] > max ? dp[i][j] : max;
		}
	}
	return max;
}

int main() {
	int result = 0; // LCS 길이
	int count = 0; // BackTracking에서 사용할 변수
	string s1, s2, lcs = "";
	cin >> s1 >> s2;	
	result = getMax(s1, s2);

	int start1 = s1.length(), start2 = s2.length();
	// BackTracking 과정 (9252 문제 핵심)
	count = result;
	for (int i = start2; i > 0; i--) {
		for (int j = start1; j > 0; j--) {
			// 문자값도 같고, dp값도 같아야 lcs에 넣는다.
			if (s1[j - 1] == s2[i - 1] && dp[i][j] == count) {
				lcs.push_back(s1[j - 1]);
				start1 = j - 1;
				count--; // dp값 check용 변수
				break;
			}
		}
	}
	std::reverse(lcs.begin(), lcs.end()); // reverse (dp값이 큰거에서부터 작은거 순서대로 넣기 때문에)
	cout << result << "\n" << lcs << "\n";	
	return 0;
}