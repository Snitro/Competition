#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

long long ans = 1, now = 1, n, m, k, size, del[100005];

long long pow(long long a, long long b) {
	long long ret = 1;
	
	for (; b; b >>= 1) {
		if (b & 1)
			ret = (ret * a) % mod;
			
		a = (a * a) % mod;
	}
	
	return ret;
}
 
pair<int, int > Not[100005];

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%lld%lld%lld", &n, &m, &k);
	
	for (int i = 1; i <= k; i++)
		scanf("%d%d", &Not[i].first, &Not[i].second);
		
	sort(Not + 1, Not + 1 + k);
	
	long long full = ((n + 1) * n / 2) % mod;
	
	for (int i = 1; i <= k; i++) {
		if (Not[i].first != Not[i - 1].first)
			del[++size] = Not[i].second;
		else if (Not[i].second != Not[i - 1].second)
			del[size] = (del[size] + Not[i].second) % mod;
	}
	
	long long tot = 1;
	
	for (int i = 1; i <= size; i++)
		tot = (tot * (full - del[i] + mod)) % mod;
	
	printf("%lld", (pow(full, m - size) * tot) % mod);
	
	return 0;
}
