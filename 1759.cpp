#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

char arr[26];
bool check[26];
int L, C; // 암호 문자 개수, 입력받은 문자 개수

void go(int start, int size) {
	if (size == 0) {
		int a_cnt = 0; // 모음 개수
		int n_cnt = 0; // 자음 개수
		std::vector<char> i_vec;
		
		for (int i = 0; i < C; i++) {
			if (check[i] == true) {
				if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') a_cnt++;
				else n_cnt++;
				i_vec.push_back(arr[i]);
			}
		}
		if (n_cnt >= 2 && a_cnt >= 1) { // 자음 개수 2개이상, 모음 개수 1개 이상일때에만 출력
			for (int i = 0; i < i_vec.size(); i++) {
				printf("%c", i_vec.at(i));
			}
			printf("\n");
		}
		return;
	}
	for (int i = start; i < C - size + 1; i++) {
		check[i] = true;
		go(i + 1, size - 1);
		check[i] = false;
	}
}

int main() {
	int i, j;
	char in;

	scanf("%d %d", &L, &C);

	for (i = 0; i < C; i++)
		scanf("%c ", &arr[i]);

	i = 0;
	while ((in = getchar()) && in != '\n') {
		if (in == ' ') continue;
		arr[i++] = in;
	}
	std::sort(arr, arr + C);
	go(0, L);
	return 0;
}