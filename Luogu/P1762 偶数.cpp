#include <iostream> 
#include <cstdio>

#define mod 1000003

using namespace std;

long long n;

long long init[50], size[50];

int init_size;

void Init() {
	size[1] = 1;
	
	for (int i = 2; i <= init_size; i++) {
		size[i] = (((((init[i - 1] + 1) % mod) * (init[i - 1] % mod)) % mod) * 500002) % mod;
		size[i] = (size[i] % mod + (size[i - 1] * 2) % mod) % mod + size[i - 1];
		size[i] %= mod;
	}
}

long long query(long long begin, long long end) {
	long long ret = 0;
	
	if(begin == 1)  {
		if (end <= 4)
			return end >= 3 ? 1 : 0; 
		
		int i = 0;
		
		while (init[i + 1] < end && i < init_size)
			i++;
			
		ret += size[i];
		
		if (init[i] + 2 <= end)
			ret = (ret + query(init[i] + 2, end)) % mod;
	} else {
		ret += (((begin - 2 + (begin - 2 - (end- begin)))) % mod) * ((end - begin + 1) % mod) * 500002 % mod;
		ret %= mod;
		ret += query(1, end - begin + 1) * 2;
		ret %= mod;
	}
	
	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%lld", &n);
	
	for (long long i = 3; i <= n; i = i * 2 + 1)
		init[++init_size] = i;
	
	Init();
	
	printf("%lld", query(1, n));
	
	return 0;
}
