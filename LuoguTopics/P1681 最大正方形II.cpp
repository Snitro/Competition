#include <iostream>
#include <cstdio>

using namespace std;

int n, m;

int datas[1505][1505];

int map[1505][1505];

int ans;

void solve() {
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= m; x++)
		    if (map[x][y]) {
		        map[x][y] = min(map[x - 1][y], map[x][y - 1]) + 1;
		        
		        if (map[x][y] >= 2 && !map[x - map[x][y] + 1][y - map[x][y] + 1])
		            map[x][y]--;
		        
		        if (map[x][y] > ans)
		            ans = map[x][y];
		    }
}

int main() {
    freopen("in.txt", "r", stdin);
    
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) { 
            scanf("%d", &datas[j][i]);
            datas[j][i] ^= (i ^ j) & 1;
            map[j][i] = datas[j][i];
        } 
    
	solve();
            
    for (int y = 1; y <= n; y++)
    	for (int x = 1; x <= m; x++)
    		map[x][y] = !datas[x][y];
    
    solve();
    
    cout << ans;
    
    return 0;
}

