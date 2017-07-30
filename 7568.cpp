#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef std::pair<int, int> iPair;
int order[51];

int main() {

	int N;
	int h, w;
	int i, j, k;
	scanf("%d", &N);
	std::vector<iPair> h_w_vec(N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &w, &h);
		h_w_vec[i] = make_pair(w, h);
	}

	for (i = 0; i < N; i++) {
		order[i] = 1;
		for (j = 0; j < N; j++) {
			if (h_w_vec[i].first < h_w_vec[j].first && h_w_vec[i].second < h_w_vec[j].second) {				
				order[i]++;
			}
		}
		printf("%d ", order[i]);
	}
	return 0;
}