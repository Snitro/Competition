#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct node {
	int a;
	int b;
	int c;

	node(int a, int b, int c) {
		this -> a = a;
		this -> b = b;
		this -> c = c;
	}

	friend bool operator < (const node & a, const node & b) {
		return a.a > b.a;
	}
};

priority_queue<node> q;

int n;

int data[400005];

int main() {
	freopen("in.txt", "r", stdin);

	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &data[i]);
	
	int k;
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		
		q.push(node(k + data[1], 1, k));
	}
	
	for (int i = 1; i <= n; i++) {
		int ans = q.top().a;
		
		q.push(node(q.top().c + data[q.top().b + 1], q.top().b + 1, q.top().c));
		
		q.pop();
		
		printf("%d ", ans);
	}

	return 0;
}
