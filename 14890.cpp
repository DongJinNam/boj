#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 100

using namespace std;

int board[MAX][MAX];
std::vector<bool> bVisited; // 0~N-1�� 0�� ����� N-1�� ����� ���η� ��������, N~2*N-1�� 0~N-1�� ������ ���η� ��������

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	int N, L;
	int ans = 0;
	cin >> N >> L;
	bVisited.resize(2 * N, false);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	std::vector<std::vector<bool>> bCheck(N,std::vector<bool>(N,false));
	// ���η� üũ
	for (int i = 0; i < N; i++) {
		bool bDiff = false;
		for (int j = 1; j < N; j++) {
			if (board[i][0] != board[i][j]) {
				bDiff = true;
				break;
			}
		}
		if (!bDiff) { // �� ���� ��� ������ ���� ���� ���,
			bVisited[i] = true;
			continue;
		}
		bool bError = false;
		for (int j = 1; j < N; j++) {
			if (bError) break; // �߰��� ������ �߻��� ��� ��� break
			if (!bCheck[i][j]) { // ���� ���ΰ� ������ ���� ���� ���
				if (board[i][j - 1] < board[i][j]) { // ���� ���� ���Ͽ� ���� ū ���
					if (j - L >= 0 && board[i][j - L] + 1 == board[i][j]) { // ���θ� ���� �� �ִ��� üũ
						for (int k = 0; k < L; k++) {
							if (!bCheck[i][j - L + k] && board[i][j - L + k] + 1 == board[i][j]) bCheck[i][j - L + k] = true; // ���θ� ���� �� �ִ� ���� ��� �ش� ���� true ǥ��
							else bError = true; // �׷��� ���� ���, ���� �߻� -> bError : true
						}
					}
					else {
						bError = true;
						break;
					}
				}
				else if (board[i][j - 1] > board[i][j]) { // ���� ���� ���Ͽ� ���� ���� ���
					if (j + L - 1 < N && board[i][j + L - 1] + 1 == board[i][j - 1]) { // ���θ� ���� �� �ִ��� üũ
						for (int k = 0; k < L; k++) {
							if (!bCheck[i][j + k] && board[i][j + k] + 1 == board[i][j - 1]) bCheck[i][j+k] = true; // ���θ� ���� �� �ִ� ���� ��� �ش� ���� true ǥ��
							else bError = true; // �׷��� ���� ���, ���� �߻� -> bError : true
						}
					}
					else {
						bError = true;
						break;
					}
				}
			}
		}
		// ����Ͽ��� line�� �湮 üũ ����
		for (int j = 0; j < N; j++)
			bCheck[i][j] = false;
		if (!bError) bVisited[i] = true;			
	}
	// ���η� üũ<���κκа� �ּ��� ����>
	for (int j = 0; j < N; j++) {
		bool bDiff = false;
		for (int i = 1; i < N; i++) {
			if (board[i][j] != board[0][j]) {
				bDiff = true;
				break;
			}
		}
		if (!bDiff) {
			bVisited[N + j] = true;
			continue;
		}
		bool bError = false;
		for (int i = 1; i < N; i++) {
			if (bError) break;
			if (!bCheck[i][j]) {
				if (board[i - 1][j] < board[i][j]) {
					if (i - L >= 0 && board[i - L][j] + 1 == board[i][j]) {
						for (int k = 0; k < L; k++) {
							if (!bCheck[i - L + k][j] && board[i - L + k][j] + 1 == board[i][j]) bCheck[i - L + k][j] = true;
							else bError = true;
						}
					}
					else {
						bError = true;
						break;
					}
				}
				else if (board[i - 1][j] > board[i][j]) {
					if (i + L - 1 < N && board[i + L - 1][j] + 1 == board[i - 1][j]) {
						for (int k = 0; k < L; k++) {
							if (!bCheck[i + k][j] && board[i+k][j] + 1 == board[i - 1][j]) bCheck[i + k][j] = true;
							else bError = true;
						}
					}
					else {
						bError = true;
						break;
					}
				}
			}
		}
		// ����Ͽ��� line�� �湮 üũ ����
		for (int i = 0; i < N; i++)
			bCheck[i][j] = false;
		if (!bError) bVisited[N+j] = true;
	}
	// ��Һ��� true�� ��� ������ �߰��Ѵ�.
	for (int i = 0; i < 2 * N; i++) {
		if (bVisited[i]) ans++;
	}
	cout << ans << "\n";
	return 0;
}