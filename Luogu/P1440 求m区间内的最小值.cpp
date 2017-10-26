#include <iostream>
#include <cstdio>

using namespace std;

int n, m;

int datas[2000005];

int q[2000005];
int begin, end;

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &datas[i]);
	
	printf("%d\n", 0);
	
	q[1] = end = begin = 1;
	
	for (int i = 2; i <= n; i++) {
		while (q[begin] + m < i && begin <= end)
			begin++;
			
		printf("%d\n", datas[q[begin]]);
		
		while (datas[q[end]] > datas[i] && begin <= end)
			end--;
		
		q[++end] = i;
	}
	
	return 0;
}
