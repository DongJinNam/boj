#include <stdio.h>
#include <vector>
#include <cmath>
#include <limits.h>

// segment tree �ʱ�ȭ
long long init(std::vector<long long> &arr, std::vector<long long> &tree, int node, int start, int end) {
	if (start == end) { // leaf node
		return tree[node] = arr[start];
	}
	else { // not leaf node
		long long r1 = init(arr, tree, node * 2, start, (start + end) / 2);
		long long r2 = init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = r1 < r2 ? r1 : r2;
		return tree[node];		
	}
}

// �������� �ּҰ� ���ϱ�.
long long min(std::vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return LONG_MAX; // node�� ��� start - end ������ ���� ���
	}
	if (left <= start && end <= right) { // start - end ���� ���� left - right (������) �� ���Ե� ���
		return tree[node];
	}
	long long r1 = min(tree, 2 * node, start, (start + end) / 2, left, right);
	long long r2 = min(tree, 2 * node + 1, (start + end) / 2 + 1, end, left, right);	
	return r1 < r2 ? r1 : r2;
}

int main() {
	int N, M, K, i_data;
	int i, j, k;
	int select, index, start, end, diff;
	long long to, total = 0;

	scanf("%d %d", &N, &M);

	std::vector<long long> arr(N);

	for (i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}

	int depth = (int)ceil(log2(N));
	int s_size = (1 << (depth + 1));
	std::vector<long long> s_tree(s_size);

	// segment tree init
	init(arr, s_tree, 1, 0, N - 1);

	while (M--) {
		scanf("%d %d", &start, &end);
		long long result = min(s_tree, 1, 0, N - 1, start - 1, end - 1);
		printf("%lld\n", result);
	}

	return 0;
}