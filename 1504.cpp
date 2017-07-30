#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define V_MAX 801

using namespace std;

int inf = 1000000000; // 한계치
bool check[V_MAX]; // 방문 여부 체크 배열
long long dp[V_MAX][V_MAX]; // DP의 결과

int main() {
	// 특정 최단 경로 구하기
	int V, E;
	int i, j, k;
	int start, from, to, add;
	int vital_point[2]; // 필수 포인트
	scanf("%d %d", &V, &E);
	for (i = 0; i < E; i++) {
		scanf("%d %d %d", &from, &to, &add);
		dp[from][to] = add;
		dp[to][from] = add;
	}
	scanf("%d %d", &vital_point[0], &vital_point[1]);
	for (i = 1; i <= V; i++) {
		for (j = 1; j <= V; j++) {
			if (i == j) dp[i][i] = 0;
			else {
				if (dp[i][j] == 0)
					dp[i][j] = inf;
			}
		}
	}
	// 플로이드
	for (k = 1; k <= V; k++) {
		for (i = 1; i <= V; i++) {
			for (j = 1; j <= V; j++) {
				if (dp[i][j] > dp[i][k] + dp[k][j])
					dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}	
	long long route1 = dp[1][vital_point[0]] + dp[vital_point[0]][vital_point[1]] + dp[vital_point[1]][V];
	long long route2 = dp[1][vital_point[1]] + dp[vital_point[1]][vital_point[0]] + dp[vital_point[0]][V];
	long long ans = route1 < route2 ? route1 : route2;
	if (ans >= inf) printf("-1\n");
	else printf("%lld\n", ans);	
	return 0;
}