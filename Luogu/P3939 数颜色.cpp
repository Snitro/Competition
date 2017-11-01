#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v[300005];

int datas[300005], n, m;

int read() {
	int f = 1, s = 0;
	char c = getchar();
	
	while (c < '0' || c > '9') {
		if (c == '-')
			f = -1;
			
		c =getchar();
	}
	
	while (c >= '0' && c <= '9') {
		s = s * 10 + c - '0';
		c = getchar();
	}
	
	return f * s;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	n = read();
	m = read();
	
	int temp, a, b, c;
	
	for (int i = 1; i <= n; i++) {
		datas[i] = read();
		v[datas[i]].push_back(i);
	}
	
	for (int i = 1; i <= m; i++) {
		temp = read();
		
		if (temp == 1) {
			a = read();
			b = read();
			c = read();
			
			int pos = upper_bound(v[c].begin(), v[c].end(), b) - v[c].begin();
			
			printf("%d\n", pos - (lower_bound(v[c].begin(), v[c].end(), a) - v[c].begin()));
		} else {
			a = read();
			
			if (datas[a] != datas[a + 1]) {
				int A = lower_bound(v[datas[a]].begin(), v[datas[a]].end(), a) - v[datas[a]].begin();
				int B = lower_bound(v[datas[a + 1]].begin(), v[datas[a + 1]].end(), a + 1) - v[datas[a + 1]].begin();
				
				swap(v[datas[a]][A], v[datas[a + 1]][B]);
				swap(datas[a], datas[a + 1]);
			}
		}
	}
	
	return 0;
}
