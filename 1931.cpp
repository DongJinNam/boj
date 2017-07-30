#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef std::pair<int, int> iPair;

int main() {
	int N;
	int i, j;
	int start, end;
	int cnt = 0;
	std::priority_queue<iPair> pq;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &start, &end);
		pq.push(make_pair(end, start));
	}

	start = pq.top().second;
	end = pq.top().first;
	pq.pop();
	// prioirty queue를 활용한 종료 시간 정렬 및 Greedy Algorithm을 통해서 카운트 세기
	while (!pq.empty()) {
		int comp_start = pq.top().second;
		int comp_end = pq.top().first;
		pq.pop();
		if (comp_end <= start) {
			end = comp_end;
			start = comp_start;
			cnt++;
		}
		if (start <= comp_start && comp_end <= end) {
			start = comp_start;
			end = comp_end;
		}
	}
	cnt++;
	printf("%d", cnt);
	return 0;
}