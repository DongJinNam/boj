#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 100

using namespace std;

int board[MAX][MAX];
std::vector<bool> bVisited; // 0~N-1은 0번 행부터 N-1번 행까지 가로로 가능한지, N~2*N-1은 0~N-1번 열까지 세로로 가능한지

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
	// 가로로 체크
	for (int i = 0; i < N; i++) {
		bool bDiff = false;
		for (int j = 1; j < N; j++) {
			if (board[i][0] != board[i][j]) {
				bDiff = true;
				break;
			}
		}
		if (!bDiff) { // 행 기준 모든 셀들의 값이 같은 경우,
			bVisited[i] = true;
			continue;
		}
		bool bError = false;
		for (int j = 1; j < N; j++) {
			if (bError) break; // 중간에 에러가 발생한 경우 즉시 break
			if (!bCheck[i][j]) { // 아직 경사로가 놓이지 않은 점인 경우
				if (board[i][j - 1] < board[i][j]) { // 이전 셀과 비교하여 값이 큰 경우
					if (j - L >= 0 && board[i][j - L] + 1 == board[i][j]) { // 경사로를 놓을 수 있는지 체크
						for (int k = 0; k < L; k++) {
							if (!bCheck[i][j - L + k] && board[i][j - L + k] + 1 == board[i][j]) bCheck[i][j - L + k] = true; // 경사로를 놓을 수 있는 점인 경우 해당 셀에 true 표시
							else bError = true; // 그렇지 않은 경우, 에러 발생 -> bError : true
						}
					}
					else {
						bError = true;
						break;
					}
				}
				else if (board[i][j - 1] > board[i][j]) { // 이전 셀과 비교하여 값이 작은 경우
					if (j + L - 1 < N && board[i][j + L - 1] + 1 == board[i][j - 1]) { // 경사로를 놓을 수 있는지 체크
						for (int k = 0; k < L; k++) {
							if (!bCheck[i][j + k] && board[i][j + k] + 1 == board[i][j - 1]) bCheck[i][j+k] = true; // 경사로를 놓을 수 있는 점인 경우 해당 셀에 true 표시
							else bError = true; // 그렇지 않은 경우, 에러 발생 -> bError : true
						}
					}
					else {
						bError = true;
						break;
					}
				}
			}
		}
		// 사용하였던 line의 방문 체크 해제
		for (int j = 0; j < N; j++)
			bCheck[i][j] = false;
		if (!bError) bVisited[i] = true;			
	}
	// 세로로 체크<가로부분과 주석은 동일>
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
		// 사용하였던 line의 방문 체크 해제
		for (int i = 0; i < N; i++)
			bCheck[i][j] = false;
		if (!bError) bVisited[N+j] = true;
	}
	// 요소별로 true인 경우 개수에 추가한다.
	for (int i = 0; i < 2 * N; i++) {
		if (bVisited[i]) ans++;
	}
	cout << ans << "\n";
	return 0;
}