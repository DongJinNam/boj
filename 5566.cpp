#include <iostream>

using namespace std;

int arr[1001]; // board �� ǥ�õ� ĭ���� ��ŭ �̵��ؾ� �ϴ����� ���� �迭
int stage[1001]; // �ܰ躰�� �� ĭ�� �̵��ϴ����� ���� �迭

int main() {
	std::ios::sync_with_stdio(false);

	int n, m;
	int count = 0; // ���� �ܰ躰�� ��� �̵����״°�.
	int pos = 0; // ���� ��ġ

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
		pos += arr[pos]; // �� �ǿ� ���� �� ��� �̵�.
	}		
	cout << count << "\n";
	return 0;
}