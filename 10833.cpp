#include <stdio.h>

int student[101];
int apple[101];

int main() {

	int N;
	int ans = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d %d", &student[i], &apple[i]);
	for (int i = 1; i <= N; i++) {
		int per = apple[i] / student[i];
		ans += (apple[i] - per * student[i]);
	}
	printf("%d", ans);
	return 0;
}