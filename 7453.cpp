#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// ���� Ž��2
	int n, i, j;
	long long ans = 0;
	scanf("%d", &n);
	std::vector<int> a(n, 0);
	std::vector<int> b(n, 0);
	std::vector<int> c(n, 0);
	std::vector<int> d(n, 0);
	std::vector<int> ans_vec;
	std::vector<int> ans_vec2;
	for (i = 0; i < n; i++)
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			ans_vec.push_back(a[i] + b[j]);
			ans_vec2.push_back(c[i] + d[j]);
		}
	}

	std::sort(ans_vec2.begin(), ans_vec2.end());

	for (int comp : ans_vec) {
		auto range = equal_range(ans_vec2.begin(), ans_vec2.end(), -comp); // lower_bound�� upper_bound�� ���ÿ� �˾Ƴ��� ���.
		ans += range.second - range.first;
	}
	printf("%lld", ans);
	return 0;
}