#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;

int f[5005];

int tot[5005];

int stack[5005], len;

int datas[5005];

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	memset(stack, 0x7f, sizeof(stack));
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &datas[i]);
		
	for (int i = 1; i <= n; i++) {
		if (datas[i] < stack[len]) {
			stack[++len] = datas[i];
			f[i] = len;
		} else {
			int l = 1, r = len;
			
			while (l < r) {
				int m = (l + r) >> 1;
				
				if (stack[m] == datas[i]) {
					l = m;
					break;
				} else if (stack[m] > datas[i])
					l = m + 1;
				else 
					r = m;
			}
			if (stack[l] != datas[i])
				stack[l] = datas[i];
			f[i] = l;
		}
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; i++) {
		tot[i] = f[i] == 1;
		for (int j = 1; j < i; j++) {
			if (datas[j] > datas[i] && f[i] == f[j] + 1)
				tot[i] += tot[j];
			if (datas[j] == datas[i] && f[j] == f[i])
				tot[j] = 0;
		}
	}
	
	for (int i = 1; i <= n; i++)
		if (f[i] == len)
			ans += tot[i];
	
	cout << len << " " << ans;
	
	return 0;
}
