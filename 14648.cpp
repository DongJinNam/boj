#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

typedef long long ll;

int init(std::vector<int> &arr, std::vector<int> &s_tree, int node, int start, int end) {
	if (start == end)
		return s_tree[node] = arr[start];
	else
		return s_tree[node] = init(arr, s_tree, node * 2, start, (start + end) / 2) + init(arr, s_tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

int sum(std::vector<int> &s_tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return s_tree[node];
	return sum(s_tree, 2 * node, start, (start + end) / 2, left, right) + sum(s_tree, 2 * node + 1, (start + end) / 2 + 1, end, left, right);
}

// 쿼리 맛보기 - segment tree를 만들어서 해결한다.
int main() {	
	int N, Q;
	int i, j;
	int select, from, to, from2, to2;
	scanf("%d %d", &N, &Q);

	int height = (int) ceil(log2(N));
	int size = (1 << (height + 1));
	std::vector<int> arr(N);
	std::vector<int> s_tree(size);

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	init(arr, s_tree, 1, 0, N - 1);
	while (Q--) {
		scanf("%d", &select);
		int res1, res2;
		ll ans;
		if (select == 1) {
			scanf("%d %d", &from, &to);			
			res1 = sum(s_tree, 1, 0, N - 1, from - 1, to - 1);			
			printf("%d\n", res1);
			std::swap(arr[from-1], arr[to-1]);
			init(arr, s_tree, 1, 0, N - 1);
		}
		else if (select == 2) {
			scanf("%d %d %d %d", &from, &to, &from2, &to2);
			res1 = sum(s_tree, 1, 0, N - 1, from - 1, to - 1);
			res2 = sum(s_tree, 1, 0, N - 1, from2 - 1, to2 - 1);
			ans = res1 - res2;
			printf("%lld\n", ans);
		}
	}
	return 0;
}