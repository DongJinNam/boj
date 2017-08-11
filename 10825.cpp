#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct student {
	int kor;
	int eng;
	int math;
	string name;
};

bool cmp(const student &s1, const student &s2) {
	if (s1.kor != s2.kor)
		return s1.kor > s2.kor;
	if (s1.eng != s2.eng)
		return s1.eng < s2.eng;
	if (s1.math != s2.math)
		return s1.math > s2.math;
	return s1.name < s2.name;

}

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	int i, j, k;	
	cin >> N;
	std::vector<student> std_vec(N);
	for (i = 0; i < N; i++) {
		cin >> std_vec[i].name >> std_vec[i].kor >> std_vec[i].eng >> std_vec[i].math;
	}
	std::stable_sort(std_vec.begin(), std_vec.end(), cmp);
	for (i = 0; i < N; i++) {
		cout << std_vec[i].name << '\n';
	}
	return 0;
}