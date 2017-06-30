#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int n,m;

bool appear[125005];

int list[125005];
int list_len = 0;

bool flg = false;

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= m; j++)
			if (!appear[i * i + j * j])
				appear[i * i + j * j] = true;
	for (int i = 0; i <= 2 * m * m; i++)
		if (appear[i])
			list[++list_len] = i;
	for (int i = 1; i <= 2 * m * m / (n - 1); i++)
		for (int j = 1; list[j] <= 2 * m * m - i * (n - 1); j++)
			if (appear[(n - 1) * i + list[j]] && appear[list[j]]) {
				bool f = true;
				for (int q = n - 2; q > 0; q--)
					if(!appear[q * i + list[j]]) {
						f = false;
						break;
					}
				if (f) {
					if (!flg)
						flg = true;
					printf("%d %d\n",list[j],i);
				}
			}
	if (flg == false)
		printf("NONE");
	return 0;
}
