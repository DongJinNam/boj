#include <iostream>
#include <vector>
#include <string>
#include <cstring>

typedef std::pair<int, int> iPair;
typedef long long ll;

using namespace std;

string colorStr[10];
ll val[11] = { 0 };
ll mul[11] = { 0 };

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	colorStr[0] = "black";
	colorStr[1] = "brown";
	colorStr[2] = "red";
	colorStr[3] = "orange";
	colorStr[4] = "yellow";
	colorStr[5] = "green";
	colorStr[6] = "blue";
	colorStr[7] = "violet";
	colorStr[8] = "grey";
	colorStr[9] = "white";

	val[0] = 0;
	mul[0] = 1;
	for (int i = 1; i < 11; i++) {
		val[i] = val[i - 1] + 1;
		mul[i] = mul[i - 1] * 10;
	}

	ll ans = 0;
	ll mulVal = 0;
	ll mulVal2 = 0;
	int i1, i2, i3;
	string c1, c2, c3;
	cin >> c1 >> c2 >> c3;
	for (int i = 0; i < 10; i++) {
		if (!strcmp(c1.c_str(), colorStr[i].c_str())) {
			i1 = i;
		}
		if (!strcmp(c2.c_str(), colorStr[i].c_str())) {
			i2 = i;
		}
		if (!strcmp(c3.c_str(), colorStr[i].c_str())) {
			i3 = i;
			mulVal = mul[i3];
			mulVal2 = mul[i3+1];
		}
	}
	ans = val[i1] * mulVal2 + val[i2] * mulVal;
	printf("%lld\n", ans);
	return 0;
}