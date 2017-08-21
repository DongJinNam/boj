#include <stdio.h>
#include <cmath>

using namespace std;

int board[1001][1001]; // 표를 저장할 배열

int main() {
	int n, size, i, j, row, col;
	int cnt = 0, round_cnt = 0;
	int next_n, max_size = 0;
	int step = 1; // 달팽이 그리기를 단계별로 진행
	int val = 0;
	scanf("%d", &n);
	scanf("%d", &val);

	max_size = n;
	size = n - 1;
	next_n = std::pow(n-2, 2);
	n *= n; // 제곱
	board[0][0] = n--;
	cnt = 0; // 단계별 카운트
	round_cnt = 0; // 몇바퀴돌았는지
	i = 1; // 회전을 시작할 행
	j = 0; // 회전을 시작할 열
	while (n > 0) {
		switch (step) {
		case 1: // 위에서 아래로
			board[i++][j] = n--;
			break;
		case 2: // 좌에서 우로
			board[i][j++] = n--;
			break;
		case 3: // 아래에서 위로
			board[i--][j] = n--;
			break;
		case 4: // 우에서 좌로
			board[i][j--] = n--;
			break;
		}
		cnt++;
		if (n == next_n) { // 한바퀴를 다 돈 경우
			step = 1; // 단계 초기화
			cnt = 0;
			round_cnt++; // 한바퀴 돌았기 때문에 회전회수 증가
			board[round_cnt][round_cnt] = n--; // left top 위치 초기화
			i = round_cnt+1;
			j = round_cnt;
			size = sqrt(next_n) - 1; // 다음 정사각형에서 단계별 처리할 크기
			next_n = std::pow(std::sqrt(next_n) - 2, 2); // 다음 정사각형의 left top 원소값		
		}
		if (cnt == size) { // 단계가 끝나는 경우
			cnt = 0;
			switch (step) {
			case 1:
				i--;
				j++;
				break;
			case 2:
				j--;
				i--;
				break;
			case 3:
				i++;
				j--;
				break;
			case 4:
				j++;
				i++;
				break;
			}
			step++;
		}
	}
	int prt_row, prt_col;
	for (i = 0; i < max_size; i++) { 
		for (j = 0; j < max_size; j++) {
			if (val == board[i][j]) { // 찾으려고 하는 값을 찾은 경우
				prt_row = i + 1; // 행
				prt_col = j + 1; // 열
			}
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("%d %d", prt_row, prt_col);
	return 0;
}