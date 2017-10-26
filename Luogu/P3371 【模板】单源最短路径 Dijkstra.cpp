#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n, m, s;

struct Edge {
	int to;
	int next;
	int value;
} edges[500005];

bool flg[10005];

int ans[10005];

int head[10005];

struct Node {
	int value;
	int to;

	Node () {
		;
	}
	
	Node (int value, int to) {
		this -> value = value;
		this -> to = to;
	}
	
	bool operator < (const Node & a) const{
		return value > a.value;
	}
};

priority_queue <Node> Q;

void add(int from, int to, int value, int id) {
	edges[id].to = to;
	edges[id].value = value;
	edges[id].next = head[from];
	head[from] = id;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &m, &s);
	
	int f, t, v;
	
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &f, &t, &v);
		
		add(f, t, v, i);
	}
	
	 for (int i = 1; i <= n; i++)
        ans[i] = 999999999;
        
    Q.push(Node(0, s));
    ans[s] = 0;
    
    while (Q.size()) {
    	Node node = Q.top();
    	Q.pop();
    	
    	if (flg[node.to])
    		continue;
    		
    	flg[node.to] = true;
    	
    	for (int i = head[node.to]; i != 0; i = edges[i].next) {
    		Edge &edge = edges[i];
    		
    		if (ans[node.to] + edge.value < ans[edge.to]) {
    			ans[edge.to] = ans[node.to] + edge.value;
    			Q.push(Node(ans[edge.to], edge.to));
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
        printf("%d ", ans[i] == 999999999 ? 2147483647 : ans[i]);
	
	return 0;
}

