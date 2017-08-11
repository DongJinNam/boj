#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::pair<int, int> iPair;

bool check[201][201][201];
std::queue <std::pair<iPair, int>> bfs;

void go(int f_i, int t_i, int from, int to, int add, int f_s, int t_s) {
	if (t_s - to >= from) {
		to += from;
		from = 0;		
	}
	else {
		from -= (t_s - to);
		to = t_s;
	}

	if (f_i == 1 && t_i == 2) {
		bfs.push(std::pair<iPair, int>(make_pair(from, to), add));
	}
	if (f_i == 1 && t_i == 3) {
		bfs.push(std::pair<iPair, int>(make_pair(from, add), to));
	}
	if (f_i == 2 && t_i == 1) {
		bfs.push(std::pair<iPair, int>(make_pair(to, from), add));
	}
	if (f_i == 2 && t_i == 3) {
		bfs.push(std::pair<iPair, int>(make_pair(add, from), to));
	}
	if (f_i == 3 && t_i == 1) {
		bfs.push(std::pair<iPair, int>(make_pair(to, add), from));
	}
	if (f_i == 3 && t_i == 2) {
		bfs.push(std::pair<iPair, int>(make_pair(add, to), from));
	}
}

int main() {

	int size_arr[3];
	int a, b, c;
	int i, j;
	std::vector<int> ans;
	scanf("%d %d %d", &size_arr[0], &size_arr[1], &size_arr[2]);

	a = 0;
	b = 0;
	c = size_arr[2];
	bfs.push(make_pair(make_pair(0, 0), c));

	while (!bfs.empty()) {
		std::pair<iPair, int> front = bfs.front();
		bfs.pop();
		int arr[3] = { front.first.first , front.first.second, front.second };

		if (check[arr[0]][arr[1]][arr[2]]) continue;

		if (arr[0] == 0) ans.push_back(arr[2]);
		check[arr[0]][arr[1]][arr[2]] = true;

		for (i = 1; i <= 3; i++) {
			for (j = 1; j <= 3; j++) {
				if (i == j) continue;
				go(i, j, arr[i - 1], arr[j - 1], arr[6 - i - j - 1], size_arr[i - 1], size_arr[j - 1]);
			}
		}
	}

	ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
	std::sort(ans.begin(), ans.end());
	for (i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	return 0;
}