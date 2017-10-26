#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int n;

int map[6][10];

bool del[6][10];

struct step {
    int x;
    int y;
    bool flag;
} steps[10];

void fall() {
    for (int x = 1; x <= 5; x++)
        for (int y = 2; y <= 7; y++)
            if (map[x][y])
                for (int i = y - 1; i >= 1 && map[x][i] == 0; i--)
                    swap(map[x][i + 1], map[x][i]);
}

bool judge() {
    for (int x = 1; x <= 5; x++)
        for (int y = 1; y <= 7; y++)
            if (map[x][y])
                return false;
    return true;
}

bool merge() {
    bool flag = false;
    
    memset(del, 0, sizeof(del));
    
    for (int x = 1; x <= 5; x++)
        for (int y = 3; y <= 7; y++)
            if (map[x][y] == map[x][y - 1] && map[x][y] == map[x][y - 2] && map[x][y]) {
                del[x][y] = del[x][y - 1] = del[x][y - 2] = true;
                flag = true;
            }
    
    for (int y = 1; y <= 7; y++)
        for (int x = 3; x <= 5; x++)
            if (map[x][y] == map[x - 1][y] && map[x][y] == map[x - 2][y] && map[x][y]) {
            	del[x][y] = del[x - 1][y] = del[x - 2][y] = true;
                flag = true;
            }
            
    for (int x = 1; x <= 5; x++)
    	for (int y = 1; y <= 7; y++)
    		if (del[x][y])
    			map[x][y] = 0;
    
    return flag;
}

void solve(int deep) {
    int temp[6][10];
    
    fall();
    while (merge())
        fall();
        
    if (judge()) {
        for (int i = 1; i < deep; i++)
            printf("%d %d %d\n", steps[i].x - 1, steps[i].y - 1, steps[i].flag ? 1 : -1);
        exit(0);
    }
    
    if (deep > n)
        return;
    
    memcpy(temp, map, sizeof(map));
    
    for (int x = 1; x <= 5; x++)
        for (int y = 1; y <= 7; y++)
            if (temp[x][y]) {
                if (temp[x][y] != temp[x + 1][y] && x < 5) {
                    steps[deep].x = x;
                    steps[deep].y = y;
                    steps[deep].flag = true;
                    
                    memcpy(map, temp, sizeof(map));
                    swap(map[x][y], map[x + 1][y]);
                    
                    solve(deep + 1);
                }
                if (temp[x - 1][y] == 0 && x > 1) {
                    steps[deep].x = x;
                    steps[deep].y = y;
                    steps[deep].flag = false;
                    
                    memcpy(map, temp, sizeof(map));
                    swap(map[x][y], map[x - 1][y]);
                    
                    solve(deep + 1);
                }
            }
        
}

int main() {
    freopen("in.txt", "r", stdin);
    
    scanf("%d", &n);
    
    int temp;
    
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 8; j++) {
            scanf("%d", &temp);
            if (!temp)
                break;
            map[i][j] = temp;
        }
    }
    
    solve(1);
    
    cout << -1;
    
    return 0;
}
