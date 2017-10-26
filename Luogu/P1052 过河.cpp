#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int l, s, t, m;

int ans = 999999999;

int f[1000005];

bool flg[1000005];

int position[105];

int pos[105];

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d%d", &l, &s, &t, &m);
	
	for (int i = 1; i <= m; i++)
		scanf("%d", &position[i]);
		
	sort(position + 1, position + 1 + m);
	memset(f, 0x7f, sizeof(f));
	
	for (int i = 1; i <= m; i++)
		pos[i] = pos[i - 1] + ((position[i] - position[i - 1]) % 2520);
		
	for (int i = 1; i <= m; i++)
		flg[pos[i]] = true;
	
	f[0] = flg[0];
	
	for (int i = 0; i <= pos[m]; i++)
		for (int w = s; w <= t; w++) {
			f[i + w] = min(f[i + w], f[i] + flg[i + w]);
			if (i + w > pos[m])
				ans = min(ans, f[i + w]);
		}
	
	cout << ans;
	
	return 0;
}
