#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int n,b;

int data[100005];
int value[100005];

map <int, int> Left;

int ans = 0;

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> b;
	int id;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&data[i]);
		if (data[i] == b)
			id = i;
	}
	value[id] = 0;
	for (int i = id; i > 0; i--) {
		if (data[i] > b)
			value[i] = value[i + 1] + 1;
		else if (data[i] < b)
			value[i] = value[i + 1] - 1;
		Left[value[i]]++;
	}
	for (int i = id; i <= n; i++) {
		if (data[i] > b)
			value[i] = value[i - 1] + 1;
		else if (data[i] < b)
			value[i] = value[i - 1] - 1;
		ans += Left[-value[i]];
	}
	cout << ans;
	return 0;
}
