#include <stdio.h>
#include <algorithm>

using namespace std;
int deg[100001];

int main() {	
	int n, q, i, j, from, to;
	scanf("%d", &n);
	for (i = 0; i < n-1; i++) {
		scanf("%d %d", &from, &to);
		deg[from]++; deg[to]++;
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		int sel, node;
		scanf("%d %d", &sel, &node);
		if (sel == 1) {
			if (deg[node] == 1) printf("no\n");
			else printf("yes\n");
		}
		else printf("yes\n");
	}
	return 0;
}