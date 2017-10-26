#include <iostream>
#include <cstdio>
#include <cstring>

#define abs(x) (x) >= 0 ? (x) : (-(x))

using namespace std;

string temp;

int add = 1, sub, n;

int sum, tot = 1, oper[200];

int main() {
	freopen("in.txt", "r", stdin);
	
	oper[1] = 1;
	for (int i = 2; ; i++) {
		cin >> temp >> temp;
		
		if (temp[0] == '+') {
			add++;
			
			oper[i] = 1;
		} else if (temp[0] == '-') {
			sub++;
			
			oper[i] = -1;
		} else
			break;
		
		tot++;
	}
	
	scanf("%d", &n);
	
	for (int i = 1; i <= tot; i++) {
		if (oper[i] == -1)
			oper[i] = -n;
		sum += oper[i];
	}
	
	int x;
	
	if (add * n - sub * 1 >= n && add * 1 - sub * n <= n) {
		puts("Possible");
		
		for (int i = 1; i <= tot && sum < n; i++)
			if (oper[i] < 0) {
				x = min(n - sum, -1 - oper[i]);
				
				oper[i] += x;
				sum += x;
			} else {
				x = min(n - sum, n - oper[i]);
				
				oper[i] += x;
				sum += x;
			}
		
		printf("%d ", oper[1]);
		
		for (int i = 2; i <= tot; i++) {
			if (oper[i] > 0)
				printf("+ ");
			else
				printf("- ");
				
			printf("%d ", abs(oper[i]));
		}
		
		printf("= %d", n);
	} else
		puts("Impossible");
	
	return 0;
}
