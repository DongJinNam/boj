#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define MAX 10001

char method[4] = {'D','S','L','R'};

bool visited[MAX];
char op[MAX];
int parent[MAX];

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;		
		cin >> a >> b;

		memset(visited, false, sizeof(bool)*MAX);
		memset(op, ' ', sizeof(char)*MAX);
		memset(parent, -1, sizeof(int)*MAX);

		std::queue<int> q;
		q.push(a);
		visited[a] = true;
		while (!q.empty()) {
			int front = q.front();
			q.pop();
			if (front == b) {				
				break;
			}
			int arr[4] = { 0 };
			int val = front;
			for (int j = 3; j >= 0; j--) {
				arr[j] = val % 10;
				val /= 10;
			}
			for (int i = 0; i < 4; i++) {
				int idx = 0;
				int mul = 1000;
				int val = 0;
				if (i == 0) {			
					val = ((2 * front) % 10000);
				}
				else if (i == 1) {
					val = (front + 9999) % 10000;
				}
				else if (i == 2) {
					val = (front % 1000) * 10 + front / 1000;
				}
				else {
					val = (front / 10) + (front % 10) * 1000;
				}
				if (!visited[val]) {
					q.push(val);
					visited[val] = true;
					op[val] = method[i];
					parent[val] = front;
				}
			}
		}
		string ans = "";
		int src = b;
		int dst = a;
		while (dst != src) {
			ans += op[src];
			src = parent[src];
		}
		std::reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
	return 0;
}