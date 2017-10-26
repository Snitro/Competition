#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int n, begin = 1, ans = 999999999;

pair <int, int > poker[100005];

void solve(int begin, int end) {
	unsigned long long MAX = 0;
	
	queue <int> que;
	
	for (int i = begin; i <= end; i++) {
		if (poker[i].second == poker[i - 1].second && i != begin)
			continue;
		
		que.push(poker[i].second);
		
		while (poker[i].second - que.front() >= n)
			que.pop();
		
		if (que.size() > MAX)
			MAX = que.size();
	}
	
	if (n - MAX < ans)
		ans = n - MAX;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &poker[i].first, &poker[i].second);
		
	sort(poker + 1, poker + 1 + n);
	
	for (int i = 2; i <= n; i++) {
		if (poker[i].first != poker[i - 1].first) {
			solve(begin, i - 1);
			begin = i;
		} else if (i == n)
			solve(begin, n);
	}
	
	cout << ans;
	
	return 0;
}
