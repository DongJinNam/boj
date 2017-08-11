#include <iostream>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N, K;
	int i;
	int ans = 1;
	int above = 1, below = 1;
	// 이항계수 문제 1
	cin >> N >> K;
	K = (N - K) < K ? (N - K) : K;

	for (i = 0; i < K; i++) {
		above *= (N - i);
		below *= (i + 1);
	}
	ans = above / below;
	cout << ans;
	return 0;
}