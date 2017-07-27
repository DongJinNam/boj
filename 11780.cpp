#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <vector>

#define MAX 100000000

int d[101][101]; // i -> j ���� �ּ� ��� (Flood Warshall ���� ���)
int m[101][101]; // i -> j ���� ���µ��� ù��°�� �湮�ϴ� ���� ��ȣ. (i -> j ��� ���̿� ��ġ�� ���ð� ���ٸ� j �� �ȴ�)
int w[101][101]; // i -> j ���� ���µ� �ʿ��� ���

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
					m[i][j] = m[i][k]; // ������ ���ؼ� ���� �迭
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