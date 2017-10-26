#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long m, d;

int top;

int last;

int len;

int stack[200001];
int datas[200001];

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d %d", &m, &d);
	
	char c[1];
	int x; 
	
	while (m--) {
		scanf("%s %d", c, &x);	
		
		if (c[0] == 'A') {
			x = (x + last) % d;
			
			datas[++len] = x;
			
			while (top && datas[stack[top]] <= x)
				top--;
			
			stack[++top] = len;
		} else {
			int y = lower_bound(stack + 1, stack + top + 1, len - x + 1) - stack;
            		printf("%d\n", last = datas[stack[y]]);
		}
	}
	
	return 0;
}
