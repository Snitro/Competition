#include <iostream>
#include <cstdio>

using namespace std;

int n = 1;

int len;

int datas[300005];
int f[300005];

int main() {
	freopen("in.txt", "r", stdin);
	
	while (~scanf("%d", &datas[n]))
		n++;
	
	n--;
	
	len = 1;
	f[1] = datas[1];
	
	for (int i = 2; i <= n; i++)  {
		if (datas[i] <= f[len])
			f[++len] = datas[i];
		else {
			int l = 1, r = len;
			
			while (l < r) {
				int m = (l + r) >> 1;
				
				if (f[m] < datas[i])
					r = m;
				else 
					l = m + 1;
			}
			
			f[l] = datas[i];
		}
	}
	
	cout << len << endl;
	
	for (int i = 1; i <= n; i++)
		f[i] = 999999999;
		
	f[1] = datas[1];
	len = 1;
	
	for (int i = 1; i <= n; i++) {
		if (datas[i] > f[len])
			f[++len] = datas[i];
		else {
			int l = 0, r = len;
			
			while (l < r) {
				int m =(l + r) >> 1;
				
				if (f[m] == datas[i]) {
					l = r = m;
					break;
				}
				
				if (f[m] < datas[i])
					l = m + 1;
				else
					r = m;
			}
			
			f[l] = datas[i];
		}
	}
	
	cout << len;
	
	return 0;
}
