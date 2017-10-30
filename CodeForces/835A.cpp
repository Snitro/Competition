#include <iostream>
#include <cstdio>

using namespace std;

int s, v1, v2, t1, t2;

int main() {
	#ifdef debug
		freopen("in.txt", "r", stdin);
	#endif
	
	cin >> s >> v1 >> v2 >> t1 >> t2;
	
	long long a = s * v1 + 2 * t1;
	long long b = s * v2 + 2 * t2;
	
	if (a == b)
		puts("Friendship");
	else if (a < b)
		puts("First");
	else 
		puts("Second");
	
	return 0;
}
