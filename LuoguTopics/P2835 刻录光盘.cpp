#include <iostream>
#include <cstdio>

using namespace std;

int n;

int f[500];

bool map[205][205];

int main() {
    freopen("in.txt", "r", stdin);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        f[i] = i;
    
    int x;
    
    for (int i = 1; i <= n; i++)
        while (scanf("%d", &x), x)
            map[i][x] = true;
    
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (map[i][k] && map[k][j])
                    map[i][j] = true;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (map[i][j])
                f[j] = f[i];
    
    int ans = 0;
    
    for (int i = 1; i <= n; i++)
        if (f[i] == i)
            ans++;
    
    cout << ans;
    
    return 0;
}
