#include <iostream>
#include <cstdio>

#define max(a, b) (a) >= (b) ? (a) : (b)

using namespace std;

long long used;

long long n, s, d;

int main() {
	scanf("%I64d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%I64d%I64d", &s, &d);
		
		if (i == 1)
			used = s;
		else {
			s = (max(0, (used - s) / d) * d) + s;
			
			while (s <= used)
				s += d;
				
			used = s;
		}
	}
	
	printf("%I64d", used);
	
	return 0;
}
