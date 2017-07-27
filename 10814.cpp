#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::vector <std::pair<int, std::pair<int, std::string>>> vec;

bool cmp(std::pair<int, std::pair<int, std::string>> lhs, std::pair<int, std::pair<int, std::string>> rhs) {
	return lhs.first < rhs.first;
}

int main() {
	std::ios::sync_with_stdio(false);

	int N, age;
	string name;
	char str[105];
	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> age;
		cin.getline(str, 105);

		name = str;
		vec[i].first = age;
		vec[i].second.first = i;
		vec[i].second.second = name;
	}
	std::stable_sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < N; i++)
		cout << vec[i].first << vec[i].second.second << endl;
	return 0;
}