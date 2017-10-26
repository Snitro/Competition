#include <cstdio>
#include <iostream>

using namespace std;

int n;

int pri[] = {0,2,3,5,7,11,13,17,19,23,29,31,37};

long long MAX = 0;
long long ans = 99999999999999999;

inline void dfs(int id, long long tot,long long sum){ // tot : 最大的约数个数  sum 当前数字 
	if (tot > MAX) {
		MAX = tot;
		ans = sum;
	} else if (tot == MAX)
		ans = min(ans, sum);
	long long t = 1;
	for (long long i = 1;; i++) {
		t *= pri[id];
		if (t * sum > n)
			break;
		dfs(id + 1, tot * (i + 1), sum * t);
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	dfs(1, 1, 1);
	cout << ans << endl;
	return 0;
}
