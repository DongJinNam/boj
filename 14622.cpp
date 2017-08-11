#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

bool dp[5000001]; // 소수 인지 아닌지 판별하는 배열
bool check[5000001]; // 소수 체크했는지 안했는지 판별하는 배열

int main() {
	std::ios::sync_with_stdio(false);
	std::priority_queue<ll> l_pq, r_pq;
	ll l_score = 0, r_score = 0;	
	int N;
	int i, j;

	// 에라토스네세스의 채로 전처리 진행
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
		cout << "소수의 신 갓대웅";
	}
	else if (l_score < r_score) {
		cout << "소수 마스터 갓규성";
	}
	else {
		cout << "우열을 가릴 수 없음";
	}
	return 0;
}