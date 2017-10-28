#include <iostream> 
#include <cstdio>
#include <algorithm>
using namespace std;

int n, datas[100005], MAX;

long long sum[100005];

int main() {
	#ifdef debug
		freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &datas[i]);
		sum[i] = sum[i - 1] + datas[i];
	}
	
	sort(sum + 1, sum + 1 + n);
	
	int k = 0;
	for (int i = 1; i <= n; i++) {
		if (sum[i] == sum[i - 1])
			k++;
		else
			k = 1;
			
		if (k > MAX) 
			MAX = k;
	}
	
	cout << n - MAX;
	
	return 0;
}
