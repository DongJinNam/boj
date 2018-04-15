#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

typedef long long ll;

using namespace std;

// 최소값 구하는 세그먼트 트리 설정
ll init(std::vector<ll> &a, std::vector<ll> &tree, int node, int start, int end) {
	if (start == end)
		tree[node] = a[start];
	else {
		int mid = (start + end) / 2;
		ll ans1 = init(a, tree, 2 * node, start, mid);
		ll ans2 = init(a, tree, 2 * node + 1, mid + 1, end);
		tree[node] = ans1 < ans2 ? ans1 : ans2;
	}
	return tree[node];
}

// 최대값 구하는 세그먼트 트리 설정
ll init_max(std::vector<ll> &a, std::vector<ll> &tree, int node, int start, int end) {
	if (start == end)
		tree[node] = a[start];
	else {
		int mid = (start + end) / 2;
		ll ans1 = init_max(a, tree, 2 * node, start, mid);
		ll ans2 = init_max(a, tree, 2 * node + 1, mid + 1, end);
		tree[node] = ans1 > ans2 ? ans1 : ans2;
	}
	return tree[node];
}

// 세그먼트 트리 특정 영역 내에서 최소값을 얻어오는 함수
ll getMin(std::vector<ll> &tree, int node, int start, int end, int left, int right) {
	if (right < start || end < left) {
		return INT_MAX;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	ll ans1 = getMin(tree, 2 * node, start, mid, left, right);
	ll ans2 = getMin(tree, 2 * node + 1, mid + 1, end, left, right);
	return std::min(ans1, ans2);
}

// 세그먼트 트리 특정 영역 내에서 최대값을 얻어오는 함수
ll getMax(std::vector<ll> &tree, int node, int start, int end, int left, int right) {
	if (right < start || end < left) {
		return -1;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	ll ans1 = getMax(tree, 2 * node, start, mid, left, right);
	ll ans2 = getMax(tree, 2 * node + 1, mid + 1, end, left, right);
	return std::max(ans1, ans2);
}

int main() {
	int vec_size, com_size;
	scanf("%d %d", &vec_size, &com_size);

	int h = ceil(log2(vec_size));
	int tree_size = 1 << (h + 1); 
	std::vector<ll> tree(tree_size,INT_MAX); // 최소 세그먼트 트리
	std::vector<ll> tree2(tree_size, -1); // 최대 세그먼트 트리
	std::vector<ll> a(vec_size,0);
	// 입력 개수가 많은 것은 scanf, printf를 사용하는 것이 좋다, 적은 것은 cin 사용해도 문제 없을 거 같다.
	for (int i = 0; i < vec_size; i++)
		scanf("%d", &a[i]);
	init(a, tree, 1, 0, vec_size - 1);
	init_max(a, tree2, 1, 0, vec_size - 1);
	for (int i = 0; i < com_size; i++) {
		int left, right;
		ll min_val = 0, max_val = 0;
		scanf("%d %d", &left, &right);
		min_val = getMin(tree, 1, 0, vec_size - 1, left - 1, right - 1);
		max_val = getMax(tree2, 1, 0, vec_size - 1, left - 1, right - 1);
		printf("%lld %lld\n", min_val, max_val);
	}
	return 0;
}