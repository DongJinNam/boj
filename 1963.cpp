#include <iostream>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

typedef std::pair<int, string> ISP;
int inf = 1000000000;
bool check[10001];

// bfs function.
int bfs(int from, int to) {
	int dp[10001] = { inf };
	int i, j;
	bool visit[10001] = { false };
	std::queue<int> bfs;
	dp[from] = 0;
	visit[from] = true;
	bfs.push(from); // bfs는 push 전에 dp 배열과 visit 배열을 미리 처리해준다.
	while (!bfs.empty()) { // bfs
		int front = bfs.front();
		int temp;
		string s = to_string(front);		
		bfs.pop();

		if (front == to) return dp[to];
		
		for (i = 0; i < 4; i++) {
			char at = s[i];
			for (j = 0; j < 10; j++) {
				s[i] = (char)j + '0';
				temp = stoi(s);
				if (temp >= 1000 && check[temp] == false && visit[temp] == false) {
					dp[temp] = dp[front] + 1;
					visit[temp] = true;
					bfs.push(temp);
				}
			}
			s[i] = at;
		}
	}
	return -1;
}

int main() {
	std::ios::sync_with_stdio(false);
	int tc, i, j, k;
	cin >> tc;

	// 에라토스네세스 알고리즘
	check[0] = check[1] = true;
	for (i = 2; i < 10000; i++) {
		if (check[i] == false) {
			for (j = i + i; j < 10000; j += i) {
				check[j] = true;
			}
		}
	}

	while (tc--) {
		string from, to;		
		cin >> from >> to;
		int from_i, to_i, ans = 0; // 출발 정수값, 끝 정수값, 답.
		from_i = stoi(from);
		to_i = stoi(to);

		if (from == to) {
			cout << "0\n";
			continue;
		}
		if (check[from_i] == true || check[to_i] == true) {
			cout << "Impossible\n";
			continue;
		}		
		ans = bfs(from_i, to_i);
		if (ans != -1) cout << ans << "\n";
		else cout << "Impossible\n";
	}
	return 0;
}