#include <stdio.h>
#include <vector>
#include <algorithm>

bool cmp(int a, int b) {
	if (a > b) return true;
	else return false;
}

int main() {
	int N;	
	int ans = 0;
	std::vector<int> a, b;
	scanf("%d", &N);
	a.resize(N);
	b.resize(N);
	for (int i = 0; i < N; i++) 
		scanf("%d", &a[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &b[i]);
	std::sort(a.begin(), a.end(), cmp);
	std::sort(b.begin(), b.end());
	for (int i = 0; i < N; i++) 
		ans += a[i] * b[i];
	printf("%d\n", ans);
	return 0;
}