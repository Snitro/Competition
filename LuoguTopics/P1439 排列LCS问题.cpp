#include <iostream>
#include <cstdio>

using namespace std;

int n, temp;

int pos[100005];

int array[100005];

int stack[100005], len;

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		pos[temp] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		array[i] = pos[temp];
	}
	
	for (int i = 1; i <= n; i++) {
		if (array[i] > stack[len]) {
			stack[++len] += array[i];
			continue;
		}
		
		int l = 1, r = len, m;
		
		while (l < r) {
			m = (l + r) >> 1;
			if (stack[m] == array[i]) {
				l = m;
				break;
			} else if (stack[m] > array[i])
				r = m;
			else
				l = m + 1;
		}
		
		stack[l] = array[i];
	}
	
	cout << len;
	
	return 0;
}
