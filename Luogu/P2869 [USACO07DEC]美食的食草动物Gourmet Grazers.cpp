#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int n, m;

long long ans;

pair <int ,int > cows[100005],things[100005];

int main() {
//    freopen("in.txt", "r", stdin);
    
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &cows[i].second, &cows[i].first);
    
    sort(cows + 1, cows + n + 1);
    
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &things[i].second, &things[i].first);
    
    sort(things + 1, things + m + 1);
    
    multiset <int> S;
    int j = m;
    
    for (int i = n; i; i--) {
        for(; j && things[j].first >= cows[i].first; j--)
            S.insert(things[j].second);
            
        multiset <int> :: iterator it = S.lower_bound(cows[i].second);
        
        if(it == S.end()) {
            cout << -1 << endl;
            return 0;
        }
        
        ans += *it;
        S.erase(it);
    }
    
    cout << ans;
    
    return 0;
}
