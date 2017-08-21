#include <stdio.h>
#include <cmath>

using namespace std;

int board[1001][1001]; // ǥ�� ������ �迭

int main() {
	int n, size, i, j, row, col;
	int cnt = 0, round_cnt = 0;
	int next_n, max_size = 0;
	int step = 1; // ������ �׸��⸦ �ܰ躰�� ����
	int val = 0;
	scanf("%d", &n);
	scanf("%d", &val);

	max_size = n;
	size = n - 1;
	next_n = std::pow(n-2, 2);
	n *= n; // ����
	board[0][0] = n--;
	cnt = 0; // �ܰ躰 ī��Ʈ
	round_cnt = 0; // ��������Ҵ���
	i = 1; // ȸ���� ������ ��
	j = 0; // ȸ���� ������ ��
	while (n > 0) {
		switch (step) {
		case 1: // ������ �Ʒ���
			board[i++][j] = n--;
			break;
		case 2: // �¿��� ���
			board[i][j++] = n--;
			break;
		case 3: // �Ʒ����� ����
			board[i--][j] = n--;
			break;
		case 4: // �쿡�� �·�
			board[i][j--] = n--;
			break;
		}
		cnt++;
		if (n == next_n) { // �ѹ����� �� �� ���
			step = 1; // �ܰ� �ʱ�ȭ
			cnt = 0;
			round_cnt++; // �ѹ��� ���ұ� ������ ȸ��ȸ�� ����
			board[round_cnt][round_cnt] = n--; // left top ��ġ �ʱ�ȭ
			i = round_cnt+1;
			j = round_cnt;
			size = sqrt(next_n) - 1; // ���� ���簢������ �ܰ躰 ó���� ũ��
			next_n = std::pow(std::sqrt(next_n) - 2, 2); // ���� ���簢���� left top ���Ұ�		
		}
		if (cnt == size) { // �ܰ谡 ������ ���
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
			if (val == board[i][j]) { // ã������ �ϴ� ���� ã�� ���
				prt_row = i + 1; // ��
				prt_col = j + 1; // ��
			}
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("%d %d", prt_row, prt_col);
	return 0;
}