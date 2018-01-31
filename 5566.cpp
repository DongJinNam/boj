#include <iostream>

using namespace std;

int arr[1001]; // board 에 표시된 칸마다 얼만큼 이동해야 하는지에 관한 배열
int stage[1001]; // 단계별로 몇 칸씩 이동하는지에 관한 배열

int main() {
	std::ios::sync_with_stdio(false);

	int n, m;
	int count = 0; // 말을 단계별로 몇번 이동시켰는가.
	int pos = 0; // 현재 위치

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> stage[i];
	}
	while (pos < n-1) {
		pos += stage[count++];
		if (pos >= n - 1) break;
		pos += arr[pos]; // 말 판에 적힌 값 대로 이동.
	}		
	cout << count << "\n";
	return 0;
}