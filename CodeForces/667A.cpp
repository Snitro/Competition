#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i, j, k) for(register int i = j; i <= k; ++i)
#define fi first
#define se second
#define D(i, j, k) for(register int i = j; i >= k; --i)
#define random(x) (rand() % (x)) + 1
#define pb push_back
#define pp pair<int, int>
#define mp make_pair
#define error(x) cerr << #x << "=" << x << endl
//***********var defination*********
const int maxn = 3e3+5;
int n, m, x, y, z;
int dist[maxn][maxn];
vector<int> to[maxn];
vector<pp> go[maxn], came[maxn];
void bfs(int s) {
    memset(dist[s], -1, sizeof(dist[s]));
    dist[s][s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
	int u = q.front();
	q.pop();
	for(auto v:to[u]) if(dist[s][v] == -1) {
	    dist[s][v] = dist[s][u] + 1;
	    q.push(v); 
	}
    }
}
bool cmp(pp a, pp b) {
    return a.fi > b.fi;
}
int main() {
#ifdef orz
    freopen("input1", "r", stdin);
#endif
    cin >> n >> m;
    F(i, 1, m) {
	cin >> x >> y;
	to[x].pb(y);
    }
    F(i, 1, n) bfs(i);
    F(i, 1, n) {
	F(j, 1, n) go[i].pb(pp(dist[i][j], j));
	F(j, 1, n) came[i].pb(pp(dist[j][i], j));
	sort(go[i].begin(), go[i].end(), cmp);
	sort(came[i].begin(), came[i].end(), cmp);
    }
    int ans = 0;
    vector<int> aans;
    F(b, 1, n) F(c, 1, n) if(b != c && dist[b][c] != -1) {
	int tmp = 0;
	vector<int> aa;
	F(i, 0, min(2, int(came[b].size())-1)) {
	    F(j, 0, min(2, int(go[c].size())-1)) {
		int a = came[b][i].se, d = go[c][j].se;
		if(a == d || a == b || a == c || b == d || d == c) continue;
		if(dist[a][b] + dist[b][c] + dist[c][d] > tmp) {
		    tmp = dist[a][b] + dist[b][c] + dist[c][d];
		    aa.clear();
		    aa.pb(a);
		    aa.pb(b);
		    aa.pb(c);
		    aa.pb(d);
		}
	    }
	}
	if(tmp  > ans) {#include <iostream>
#include <cstdio>
#include <cmath>

#define pi acos(-1)

using namespace std;

double d, h, v, e;

int main() {
	cin >> d >> h >> v >> e;
	
	double S = pi * (d / 2) * (d / 2);
	
	if (v / S < e) {
		puts("NO");
		return 0;
	} else {
		puts("YES");
		printf("%.15f", h / ((v / S) - e));
	}
	
	return 0;
}
	    ans = tmp;
	    aans = aa;
	}
    }
    for(auto x: aans) cout << x << ' ';
    return 0;
}
