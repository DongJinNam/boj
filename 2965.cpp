#include <stdio.h>
int main() {
	int pos[3];
	int ans;
	scanf("%d %d %d", &pos[0], &pos[1], &pos[2]);
	ans = (pos[2] - pos[1]) > (pos[1] - pos[0]) ? (pos[2] - pos[1]) : (pos[1] - pos[0]);
	printf("%d\n", --ans);
	return 0;
}