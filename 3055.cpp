#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

typedef std::pair<int, int> iPair;

using namespace std;

string str[50];
int yy[4] = { 0,0,1,-1 };
int xx[4] = { 1,-1,0,0 };

bool check(int ny, int nx, int r, int c) {
	return ny >= 0 && ny < r && nx >= 0 && nx < c;
}

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);

	int r, c;
	int s_r, s_c, d_r, d_c, p_r, p_c;
	bool bPool = false;
	std::vector<int> pool_vec;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (str[i][j] == 'D') {
				d_r = i;
				d_c = j;
			}
			if (str[i][j] == 'S') {
				s_r = i;
				s_c = j;
			}
			if (str[i][j] == '*') {
				p_r = i;
				p_c = j;
				pool_vec.push_back(i*c + j);
				bPool = true;
			}
		}
	}

	int ans = -1;
	std::queue<iPair> q;
	std::queue<iPair> p_q;
	std::vector<std::vector<bool>> visited(r, std::vector<bool>(c, false));
	q.push(make_pair(0,s_r*c+s_c));
	visited[s_r][s_c] = true;
	if (bPool) {
		for (int i = 0; i < pool_vec.size(); i++) {
			p_r = pool_vec[i] / c;
			p_c = pool_vec[i] % c;
			p_q.push(make_pair(0, p_r*c + p_c));
			visited[p_r][p_c] = true;
		}
	}	
	while (!q.empty()) {
		iPair front = q.front();		
		int y = front.second / c;
		int x = front.second % c;		
		q.pop();

		if (y == d_r && x == d_c) {
			ans = front.first;
			break;
		}
		if (front.first == p_q.front().first) {
			int pq_size = p_q.size();
			for (int i = 0; i < pq_size; i++) {
				iPair front_p = p_q.front();
				int py = front_p.second / c;
				int px = front_p.second % c;
				for (int j = 0; j < 4; j++) {
					int ny = py + yy[j];
					int nx = px + xx[j];
					if (check(ny, nx, r, c) && (str[ny][nx] == '.' || str[ny][nx] == 'S') && visited[ny][nx] == false) {
						p_q.push(make_pair(front_p.first + 1, ny*c + nx));
						visited[ny][nx] = true;
					}
				}
				p_q.pop();
			}
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + yy[i];
			int nx = x + xx[i];
			if (check(ny, nx, r, c) && (str[ny][nx] == '.' || str[ny][nx] == 'D') && visited[ny][nx] == false) {
				q.push(make_pair(front.first+1, ny*c + nx));
				visited[ny][nx] = true;
			}
		}
	}
	if (ans != -1)
		cout << ans << "\n";
	else
		cout << "KAKTUS" << "\n";
	return 0;
}