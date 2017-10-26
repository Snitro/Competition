#include <iostream>
#include <cstdio>

using namespace std;

int n, k, End;

long long ans;

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &k);
	
	ans += (long long)n * k;
	
	for (int i = 1; i <= min(n, k);) {
		End = min(k / (k / i), n);
		
		ans -= (long long)(k / i) * (i + End) * (End - i + 1) / 2;
		
		i = End + 1;
	}
	
	printf("%lld", ans);
	
	return 0;
}
