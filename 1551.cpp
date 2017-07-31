#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[21][21];

int main() {

	int N, K;
	int i, j, prev_index = 0;
	string s;
	std::vector<int> num_vec;

	cin >> N >> K;
	cin >> s;

	for (i = 0; i < s.length(); i++) {
		if (i == s.length() - 1) {
			string temp = s.substr(prev_index, i - prev_index + 1);
			int i_temp = stoi(temp);
			num_vec.push_back(i_temp);
			dp[0][num_vec.size() - 1] = i_temp;
			break;
		}

		if (s[i] == ',') {
			string temp = s.substr(prev_index, i);
			int i_temp = stoi(temp);
			prev_index = i + 1;
			num_vec.push_back(i_temp);
			dp[0][num_vec.size() - 1] = i_temp;
		}
	}

	for (i = 1; i <= K; i++) {		
		for (j = 0; j < num_vec.size() - i; j++) {
			dp[i][j] = dp[i - 1][j + 1] - dp[i - 1][j];
		}	
	}
	for (i = 0; i < num_vec.size() - K; i++) {
		if (i == num_vec.size() - K - 1) printf("%d", dp[K][i]);
		else printf("%d,", dp[K][i]);
	}
	return 0;
}