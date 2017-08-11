#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

bool dp[5000001]; // �Ҽ� ���� �ƴ��� �Ǻ��ϴ� �迭
bool check[5000001]; // �Ҽ� üũ�ߴ��� ���ߴ��� �Ǻ��ϴ� �迭

int main() {
	std::ios::sync_with_stdio(false);
	std::priority_queue<ll> l_pq, r_pq;
	ll l_score = 0, r_score = 0;	
	int N;
	int i, j;

	// �����佺�׼����� ä�� ��ó�� ����
	dp[0] = dp[1] = true;
	for (i = 2; i < 5000000; i++) {
		if (dp[i] == false) {
			for (j = i + i; j < 5000000; j += i) {
				dp[j] = true;
			}
		}
	}

	cin >> N;
	while (N--) {
		int left, right;
		ll temp[3];
		cin >> left >> right;

		if (dp[left] == true) {
			if (r_pq.size() < 3) {
				r_score += 1000;
			}
			else {
				for (i = 0; i < 3; i++) {
					temp[i] = r_pq.top();
					r_pq.pop();
				}
				r_score += temp[2];
				r_pq.push(temp[2]);
				r_pq.push(temp[1]);
				r_pq.push(temp[0]);
			}
		}
		else {
			if (check[left] == false) {
				check[left] = true;
				l_pq.push(left);
			}
			else {
				l_score -= 1000;
			}
		}

		if (dp[right] == true) {
			if (l_pq.size() < 3) {
				l_score += 1000;
			}
			else {
				for (i = 0; i < 3; i++) {
					temp[i] = l_pq.top();
					l_pq.pop();
				}
				l_score += temp[2];
				l_pq.push(temp[2]);
				l_pq.push(temp[1]);
				l_pq.push(temp[0]);
			}
		}
		else {
			if (check[right] == false) {
				check[right] = true;
				r_pq.push(right);
			}
			else {
				r_score -= 1000;
			}
		}
	}

	if (l_score > r_score) {
		cout << "�Ҽ��� �� �����";
	}
	else if (l_score < r_score) {
		cout << "�Ҽ� ������ ���Լ�";
	}
	else {
		cout << "�쿭�� ���� �� ����";
	}
	return 0;
}