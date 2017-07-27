#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <vector>

#define MAX 100000000

int d[101][101]; // i -> j 까지 최소 비용 (Flood Warshall 연산 결과)
int m[101][101]; // i -> j 까지 가는데에 첫번째로 방문하는 도시 번호. (i -> j 경로 사이에 거치는 도시가 없다면 j 가 된다)
int w[101][101]; // i -> j 까지 가는데 필요한 비용

// flood Warshall

int main() {

	int N, M;
	int i, j, k;
	int in, in_2, add;

	scanf("%d", &N);
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &in, &in_2, &add);
		if (w[in][in_2] != 0) w[in][in_2] = add < w[in][in_2] ? add : w[in][in_2];		
		else w[in][in_2] = add;
		m[in][in_2] = in_2;
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (w[i][j] > 0) d[i][j] = w[i][j];
			else {
				if (i == j) d[i][j] = 0;
				else d[i][j] = MAX;
			}
		}
	}

	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					m[i][j] = m[i][k]; // 추적을 위해서 남긴 배열
				}
			}
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			std::vector<int> vec;
			if (i == j) printf("0\n");
			else {
				// tracing
				int u, v;
				u = i;
				v = j;
				vec.push_back(u);
				while (1) {
					if (m[u][v] == 0) break;
					else {
						u = m[u][v];
						vec.push_back(u);
					}
				}
				printf("%d ", vec.size());
				for (k = 0; k < vec.size(); k++) {
					printf("%d ", vec.at(k));
				}
				printf("\n");
			}
		}
	}
	return 0;
}