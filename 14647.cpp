#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

string arr[500][500];
ll cnt_arr[500][500];

int main() {
	std::ios::sync_with_stdio(false);

	int N, M;
	int i, j, k;
	ll ans = 0; // 9가 최대로 많이 나오는 행, 열에서의 9의 개수
	ll temp = 0, row = 0, col = 0;
	ll total = 0;
	cin >> N >> M;

	for (i = 1; i <= N; i++) {
		row = 0;
		for (j = 1; j <= M; j++) {
			cin >> arr[i][j];	
			cnt_arr[i][j] = 0;
			for (k = 0; k < arr[i][j].length(); k++) {
				char at = arr[i][j].at(k);
				if (at == '9') {
					cnt_arr[i][j]++;
					row++;
				}
			}
		}
		total += row;
		ans = row > ans ? row : ans;
	}
	for (j = 1; j <= M; j++) {
		col = 0;
		for (i = 1; i <= N; i++) {
			col += cnt_arr[i][j];
		}
		ans = col > ans ? col : ans;
	}
	cout << total - ans << endl;
	return 0;
}