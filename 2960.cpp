#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool check[1001]; // �Ҽ��̸� false, �Ҽ��� �ƴϸ� true

// �����佺�׳׽��� ü
int main() {
	int n, k;
	int cnt = 0, ans = 0;
	bool bFind = false;

	scanf("%d %d", &n, &k);

	for (int i = 2; i <= n; i++) {
		if (bFind) break;
		if (check[i] == false) {
			for (int j = i; j <= n; j+=i) {
				if (check[j] == false) cnt++;
				if (i != j) check[j] = true;				
				if (cnt == k) {
					ans = j;
					bFind = true;
					break;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}