#include <iostream>
#include <string>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	// NN ¹®Á¦
	string s;
	int M;
	int i;
	int N, len;


	cin >> s >> M;
	N = stoi(s);
	len = s.length();

	if (M > len * N) {
		for (i = 0; i < len*N; i++)
			cout << s.at(i % len);
	}
	else {
		for (i = 0; i < M; i++)
			cout << s.at(i % len);
	}
	return 0;
}