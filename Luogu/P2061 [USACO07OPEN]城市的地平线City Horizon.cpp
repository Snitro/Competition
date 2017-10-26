#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

long long ans;

int n;

struct Node {
	int begin;
	int end;
	int value;
	
	bool operator < (Node a) const {
		return this -> value < a.value;
	}
} nodes[40005];

int pos[80005];

priority_queue <Node> que;

bool cmp(Node a, Node b) {
	return a.begin < b.begin;
}

bool _cmp(int a, int b) {
	return a < b;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &nodes[i].begin, &nodes[i].end, &nodes[i].value);
		pos[i * 2] = nodes[i].end;
		pos[i * 2 - 1] = nodes[i].begin;
	}
	
	sort(pos + 1, pos + 1 + n * 2, _cmp);
	sort(nodes + 1, nodes + 1 + n, cmp);
	
	int put = 0;
	for (int i = 1; i < n * 2; i++) {
		while (que.size() && que.top().end <= pos[i])
			que.pop();
		while (pos[i] <= nodes[put + 1].begin && nodes[put + 1].begin < pos[i + 1])
			que.push(nodes[++put]);
		
		if (que.size())
			ans += (long long)(pos[i + 1] - pos[i]) * que.top().value;
	}
	
	printf("%lld", ans);
	
	return 0;
}
