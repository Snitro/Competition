#include <iostream> 
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Node {
	int pos;
	int now;
	int step;
	
	Node () {
		;
	}
	
	Node (int pos, int now, int step) {
		this -> pos = pos;
		this -> now = now;
		this -> step = step;
	}
};

char str[50];

int n, len;

queue <Node> que;

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%s%d", str, &n);
	
	len = strlen(str);
	
	que.push(Node(0, 0, 0));
	
	Node front;
	
	while (que.size()) {
		front = que.front();
		que.pop();
		
		if (front.pos == len) {
			if (front.now == n) {
				printf("%d", front.step - 1);
				return 0;
			} else
				continue;
		}
		
		int res = 0;
		
		for (int i = front.pos; i < len; i++) {
			res = res * 10 + str[i] - '0';
			
			if (res <= n) {
				que.push(Node(i + 1, front.now + res, front.step + 1));
			} else
				break;
		}
	}
	
	printf("-1");
	
	return 0;
}
