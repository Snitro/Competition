#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n, m;

int ans = 999999999;

int flg[20000000];

struct Data {
	int t;
	int w;
	
	Data(int, int);
	
	
};

queue <Data> Q;

Data::Data(int t, int w) {
	this -> t = t;
	this -> w = w;
}

struct bug {
	int t;
	char befor[30];
	char after[30];
} bugs[110];

int use(int id, int ch) {
	char *after = bugs[id].after;
	
	for (int i = 0; i < n; i++) {
		if (after[i] == '+')
			ch |= 1 << i;
		else if (after[i] == '-') {
			ch = ~ch;
			ch |= 1 << i;
			ch = ~ch;
		}
	}
	
	return ch;
}

bool matching(int id, int ch) {
	char *befor = bugs[id].befor;
	
	for (int i = 0; i < n; i++) {
		if (befor[i] == '+')
			if (!(ch & (1 << i)))
				return false;
				
		if (befor[i] == '-') 
			if (ch & (1 << i))
				return false;
	}
	
	return true;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	memset(flg, 0x7f, sizeof(flg));
	
	scanf("%d%d", &n ,&m);
	
	for (int i = 1; i <= m; i++)
		scanf("%d%s%s", &bugs[i].t, &bugs[i].befor, &bugs[i].after);
	
	int b = 0;
	for (int i = 0; i < n; i++)
		b |= 1 << i;
	
	Q.push(Data(0, b));
	
	while (Q.size()) {
		Data data = Q.front();
		Q.pop();
		
		if (data.w == 0) {
			if (data.t < ans)
				ans = data.t;
		}
		
		for (int i = 1; i <= m; i++)
			if (matching(i, data.w)) {
				int n = data.t + bugs[i].t;
				int to = use(i, data.w);
				
				if (n > flg[to])
					continue;
				
				flg[to] = n;
				
				Q.push(Data(n, to));
			}
	}
	
	if (ans == 999999999)
		cout << 0;
	else
		cout << ans;
	
	return 0;
}
