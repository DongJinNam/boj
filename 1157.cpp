#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000001

struct Data {
	char ch;
	int count;
};

std::vector<Data> data_vec;
char str[MAX];

bool compare(Data &a, Data &b) {
	if (a.count > b.count)
		return true;
	else if (a.count == b.count)
		return a.ch < b.ch;
	else
		return false;
}

int main() {
	char ch;
	int len = 0;
	int i, j;
	while (scanf("%c", &ch) && ch >= 'A' && ch <= 'z') {
		str[len++] = ch;
	}
	for (i = 0; i < 26; i++) {
		Data d;
		d.ch = (char) 'A' + i;
		d.count = 0;
		data_vec.push_back(d);
	}
	for (i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			int idx = (int)(str[i] - 'A');
			data_vec[idx].count++;
		}
		if (str[i] >= 'a' && str[i] <= 'z') {
			int idx = (int)(str[i] - 'a');
			data_vec[idx].count++;
		}
	}
	std::sort(data_vec.begin(), data_vec.end(),compare);
	if (data_vec[0].count == data_vec[1].count)
		printf("?\n");
	else
		printf("%c\n", data_vec[0].ch);
	return 0;
}