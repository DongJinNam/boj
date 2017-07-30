#include <stdio.h>

int team1[10];
int team2[10];

int main() {

	int i, j;
	int score1 = 0, score2 = 0;
	bool bReverse = false;

	for (i = 1; i < 10; i++)
		scanf("%d", &team1[i]);
	for (i = 1; i < 10; i++)
		scanf("%d", &team2[i]);

	for (i = 1; i < 10; i++) {
		score1 += team1[i];
		if (score1 > score2) bReverse = true;
		score2 += team2[i];
	}
	if (bReverse) printf("Yes\n");
	else printf("No\n");
	return 0;
}