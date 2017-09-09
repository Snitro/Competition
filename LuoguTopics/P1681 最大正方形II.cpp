#include <iostream>
#include <cstdio>

using namespace std;

int map[1505][1505];

int f[1505][1505][2];

int n, m, ans;

int main() {
    freopen("in.txt", "r", stdin);
    
    scanf("%d%d", &n, &m);
    
    for (int y = 1; y <= n; y++)
        for (int x = 1; x <= m; x++)
            scanf("%d", &map[x][y]);
            
    for (int y = 1; y <= n; y++)
        for (int x = 1; x <= m; x++) {
            f[x][y][map[x][y]] = min(f[x - 1][y][!map[x][y]], f[x][y - 1][!map[x][y]]) + 1;
            
            if (f[x][y][map[x][y]] > 1 && map[x - f[x][y][map[x][y]] + 1][y - f[x][y][map[x][y]] + 1] != map[x][y])
                f[x][y][map[x][y]]--;
            
            if (f[x][y][map[x][y]] > ans)
                ans = f[x][y][map[x][y]];
        }
    
    cout << ans;
    
    return 0;
}
