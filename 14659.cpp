#include <stdio.h>
#include <vector>

using namespace std;

int main() {

	int n, i, j;
	std::vector<int> num_vec;

	scanf("%d", &n);
	num_vec.resize(n, 0);

	for (i = 0; i < n; i++)
		scanf("%d", &num_vec[i]);
	
	int max = 0;
	int val = num_vec[0];
	int cnt = 0;
	for (i = 1; i < n; i++) {
		if (val > num_vec[i]) {
			cnt++;
		}
		else {
			max = cnt > max ? cnt : max;
			cnt = 0;
			val = num_vec[i];
		}
	}
	if (cnt > max) max = cnt;
	printf("%d", max);
	return 0;
}