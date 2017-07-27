#include <stdio.h>

int main() {

	int A, B, V, temp, pos = 0, cnt = 0, diff;
	int prev;
	scanf("%d %d %d", &A, &B, &V);
	temp = V - A;
	diff = A - B;
	if (temp > 0) {
		prev = temp / diff;
		cnt = prev;
		pos = prev * diff;
		while (pos < V) {
			if (pos + A >= V) {
				cnt++;
				break;
			}
			pos += diff;
			cnt++;
		}
	}
	else {
		cnt = 1;
	}	
	printf("%d\n", cnt);
	return 0;
}