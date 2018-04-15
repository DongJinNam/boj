#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int board[21][21];
int n;

int dfs(std::vector<int> team) {
	if (team.size() == n / 2) {
		std::vector<int> o_team;
		int beg = 0;
		int ans1 = 0;
		int ans2 = 0;
		for (int i = 1; i <= n; i++) {
			if (beg < n / 2 && team[beg] == i) beg++;
			else o_team.push_back(i);
		}
		for (int i = 0; i < team.size(); i++) {
			for (int j = i + 1; j < team.size(); j++) {
				ans1 += board[team[i]][team[j]];
				ans1 += board[team[j]][team[i]];
			}
		}
		for (int i = 0; i < o_team.size(); i++) {
			for (int j = i + 1; j < o_team.size(); j++) {
				ans2 += board[o_team[i]][o_team[j]];
				ans2 += board[o_team[j]][o_team[i]];
			}
		}
		return ans1 - ans2 > 0 ? ans1 - ans2 : ans2 - ans1;
	}
	int ans = INT_MAX;
	for (int i = team.back() + 1; i <= n; i++) {
		std::vector<int> copy_vec(team);
		copy_vec.push_back(i);
		int get_val = dfs(copy_vec);
		ans = get_val < ans ? get_val : ans;
	}
	return ans;
}

int main() {	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	std::vector<int> team_vec;
	team_vec.push_back(1);
	printf("%d\n", dfs(team_vec));
	return 0;
}