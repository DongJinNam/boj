#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

typedef std::pair<int, int> iPair;

struct Compare {
	bool operator() (const iPair &a, const iPair &b) {
		if (a.first > b.first)
			return true;
		else if (a.first == b.first) {
			if (a.second > b.second)
				return true;
			else
				return false;
		}
		else return false;
	}
};

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	std::vector<int> arr;
	std::priority_queue<iPair, std::vector<iPair>, Compare> pq;
	int n;
	cin >> n;
	arr.resize(n);
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0)
			pq.push(iPair(arr[i], arr[i]));
		else if (arr[i] == 0) {
			if (pq.size() == 0)
				cout << "0\n";
			else {
				iPair front = pq.top();
				pq.pop();
				cout << front.second << "\n";
			}
		}
		else
			pq.push(iPair(-arr[i], arr[i]));
	}

	return 0;
}