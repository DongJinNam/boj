#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	char left;
	char right;
	Node() {
		left = '.';
		right = '.';
	}
};

std::vector<Node> node_char(26);
int N;

void preorder(char root) {
	cout << root;
	if (node_char[root - 'A'].left != '.') {
		preorder(node_char[root - 'A'].left);
	}
	if (node_char[root - 'A'].right != '.') {
		preorder(node_char[root - 'A'].right);
	}
}

void inorder(char root) {
	if (node_char[root - 'A'].left != '.') {
		inorder(node_char[root - 'A'].left);
	}
	cout << root;
	if (node_char[root - 'A'].right != '.') {
		inorder(node_char[root - 'A'].right);
	}
}

void postorder(char root) {	
	if (node_char[root - 'A'].left != '.') {
		postorder(node_char[root - 'A'].left);
	}
	if (node_char[root - 'A'].right != '.') {
		postorder(node_char[root - 'A'].right);
	}
	cout << root;
}

int main() {	
	std::ios::sync_with_stdio(false);

	int i, j;
	cin >> N;
	
	for (i = 0; i < N; i++) {
		int cnt = 0;
		int select = 0;
		char t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		node_char[t1 - 'A'].left = t2;
		node_char[t1 - 'A'].right = t3;
	}
	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
	cout << endl;
	return 0;
}