#include <stdio.h>
#include <vector>
#include <cmath>

// segment tree 초기화
long long init(std::vector<long long> &arr, std::vector<long long> &tree, int node, int start, int end) {
	if (start == end) { // leaf node
		return tree[node] = arr[start];
	}
	else { // not leaf node
		return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2) + init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

// 구간합 구하기
long long sum(std::vector<long long> &tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0; // node의 담당 start - end 영역에 없는 경우
	}
	if (left <= start && end <= right) { // start - end 영역 내에 left - right (구간값) 이 포함된 경우
		return tree[node];
	}
	return sum(tree, 2 * node, start, (start + end) / 2, left, right) + sum(tree, 2 * node + 1, (start + end) / 2 + 1, end, left, right);
}

// index에 해당하는 값 차이를 적용해서 segment tree에 적용
void update(std::vector<long long> &tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] += diff;
	if (start != end) {
		update(tree, 2 * node, start, (start + end) / 2, index, diff);
		update(tree, 2 * node + 1, (start + end) / 2 + 1, end, index, diff);
	}
}


int main() {
	int N, M, K, i_data;
	int i, j, k;
	int select, index, start, end, diff;
	long long to, total = 0;

	scanf("%d %d %d", &N, &M, &K);

	std::vector<long long> arr(N);

	for (i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}
	
	int depth = (int)ceil(log2(N));
	int s_size = (1 << (depth + 1));
	std::vector<long long> s_tree(s_size);
	
	// segment tree
	init(arr, s_tree, 1, 0, N-1);

	for (i = 0; i < M + K; i++) {
		scanf("%d", &select);
		if (select == 1) {
			scanf("%d %lld", &index, &to);
			index--;
			diff = to - arr[index];
			arr[index] = to;
			update(s_tree, 1, 0, N - 1, index, diff);
		}
		else if (select == 2) {
			scanf("%d %d", &start, &end);
			long long result = sum(s_tree, 1, 0, N - 1, start - 1, end - 1);
			printf("%lld\n", result);
		}
	}

	return 0;
}