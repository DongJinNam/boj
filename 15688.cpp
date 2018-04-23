#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	std::vector<int> num;
	scanf("%d", &n);
	num.resize(n, 0);
	for (int i = 0; i < n; i++) 
		scanf("%d", &num[i]);
	std::sort(num.begin(), num.end());
	for (auto it : num)
		printf("%d\n", it);
	return 0;
}