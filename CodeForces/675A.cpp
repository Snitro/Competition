#include <iostream>
#include <cstdio>

using namespace std;

int a, b, c;

int main() {
	#ifdef debug
		freopen("in.txt", "r", stdin);
	#endif
	
	scanf("%d%d%d", &a, &b, &c);
	
	if ((a > b && c > 0) || (a < b && c < 0)) {
		puts("NO");
		return 0;
	} else if (a == b) {
		puts("YES");
		return 0;
	} else {
		if (c != 0 && (b - a) % c == 0) {
			puts("YES");
			return 0;
		}
		
		puts("NO");
	}
	
	return 0;
}
