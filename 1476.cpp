#include <stdio.h>

int main() {
	int E, S, M;
	int t_E = 0, t_S = 0, t_M = 0;
	int year = 0;
	bool bFind = false;

	scanf("%d %d %d", &E, &S, &M);	

	while (1) {
		if (t_E == E && t_S == S && t_M == M) {
			break;
		}
		t_E++;
		t_S++;
		t_M++;
		year++;
		if (t_E > 15) t_E = 1;
		if (t_S > 28) t_S = 1;
		if (t_M > 19) t_M = 1;		
	}
	
	printf("%d\n", year);
	return 0;
}