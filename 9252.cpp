#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][1001] = { 0 };

// ������ LCS ������ ����
int getMax(string s1, string s2) {
	int max = 0;
	for (int i = 1; i <= s2.length(); i++) {
		for (int j = 1; j <= s1.length(); j++) {
			if (s1[j - 1] == s2[i - 1]) { // �� ���ڿ��� ���ڰ� ���� ��ġ�� ���
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else { // ���ڰ� ���� �ٸ� ���
				dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			}
			max = dp[i][j] > max ? dp[i][j] : max;
		}
	}
	return max;
}

int main() {
	int result = 0; // LCS ����
	int count = 0; // BackTracking���� ����� ����
	string s1, s2, lcs = "";
	cin >> s1 >> s2;	
	result = getMax(s1, s2);

	int start1 = s1.length(), start2 = s2.length();
	// BackTracking ���� (9252 ���� �ٽ�)
	count = result;
	for (int i = start2; i > 0; i--) {
		for (int j = start1; j > 0; j--) {
			// ���ڰ��� ����, dp���� ���ƾ� lcs�� �ִ´�.
			if (s1[j - 1] == s2[i - 1] && dp[i][j] == count) {
				lcs.push_back(s1[j - 1]);
				start1 = j - 1;
				count--; // dp�� check�� ����
				break;
			}
		}
	}
	std::reverse(lcs.begin(), lcs.end()); // reverse (dp���� ū�ſ������� ������ ������� �ֱ� ������)
	cout << result << "\n" << lcs << "\n";	
	return 0;
}