#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Node {
	int left;
	int right;
};

Node arr[10001];
bool check[10001]; // root node 찾기 위한 배열
int depth[10001];
std::vector<int> dep_vec[10001];
int inorder_cnt = 0;
int dep_max = 0;

void preorder(int me, int count) {
	depth[me] = count;
	dep_max = count > dep_max ? count : dep_max;
	if (arr[me].left != -1) preorder(arr[me].left, count + 1);
	if (arr[me].right != -1) preorder(arr[me].right, count + 1);
}

void inorder(int me) {	
	if (arr[me].left != -1) inorder(arr[me].left);
	dep_vec[depth[me]].push_back(++inorder_cnt);
	if (arr[me].right != -1) inorder(arr[me].right);
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	int i;
	int me, l, r, root;
	cin >> n;

	for (i = 1; i <= n; i++) {
		cin >> me >> l >> r;
		arr[me].left = l;
		arr[me].right = r;
		check[l] = true;
		check[r] = true;
	}
	for (i = 1; i <= n; i++) {
		if (check[i] == false) {
			root = i;
			break;
		}
	}
	preorder(root, 0);
	inorder(root);

	int h, wid_max = 0;
	for (i = 0; i <= dep_max; i++) {
		std::sort(dep_vec[i].begin(), dep_vec[i].end());
		int min, max;
		int size = dep_vec[i].size();
		if (dep_vec[i].size() > 1) {
			max = dep_vec[i][size-1];
			min = dep_vec[i][0];
		}
		else {
			max = min = dep_vec[i][0];
		}
		if ((max - min + 1) > wid_max) {
			h = i;
			wid_max = (max - min + 1);
		}
	}
	cout << h+1 << " " << wid_max;
	return 0;
}