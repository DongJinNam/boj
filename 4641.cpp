#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	while (1) {

		std::vector<int> num_vec;
		int in, i, j;
		int ans = 0;

		scanf("%d", &in);
		if (in == -1) break;

		num_vec.push_back(in);
		while (scanf("%d", &in) && in != 0) {
			num_vec.push_back(in);
		}


		for (i = 0; i < num_vec.size(); i++) {
			for (j = 0; j < num_vec.size(); j++) {
				if (i == j) continue;
				if (num_vec[j] == 2 * num_vec[i]) ans++;
			}
		}

		printf("%d\n", ans);

	}
	return 0;
}