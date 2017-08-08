#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

    
queue <int> q;
queue <int> ans;

int n, m;

int du[50];

bool vis[50];

int s;

struct Edge {
    int to;
    int next;
} edges[110];

int head[50];

void add(int from, int to, int id) {
    edges[id].to = to;
    edges[id].next = head[from];
    head[from] = id;
}

int judge() {
    bool v = false, unpd = false;
    int Du[50];
    
    while (ans.size())
        ans.pop();
    
    for (int i = 1; i <= 26; i++) {
        Du[i] = du[i];
        
        if (Du[i] == 0 && vis[i]) {
            if (!v)
                v = true;
            else
                unpd = true;
            q.push(i);
            ans.push(i);
        }
    }
        
    if (q.empty())
        return 1;
    
    while (!q.empty()) {
        int x = q.front();
        v = false;
        q.pop();
        
        for (int i = head[x]; i; i = edges[i].next) {
            Edge &edge = edges[i];
            Du[edge.to]--;
            
            if (!Du[edge.to]) {
                q.push(edge.to);
                if (!v)
                    v = true;
                else
                    unpd = true;
                
                ans.push(edge.to);
            }
        }
    }
    
    if (ans.size() != s)
        return 1;
        
    if (unpd)
        return 2;
    
    return 0;
}

int main() {
    freopen("in.txt", "r", stdin);
    
    cin >> n >> m;
    
    string data;
    
    for (int i = 1; i <= m; i++) {
        cin >> data;
        
        if (!vis[data[0] - 'A' + 1]) {
            vis[data[0] - 'A' + 1] = true;
            s++;
        }
        
        if (!vis[data[2] - 'A' + 1]) {
            vis[data[2] - 'A' + 1] = true;
            s++;
        }
        
        add(data[0] - 'A' + 1, data[2] - 'A' + 1, i);
        
        du[data[2] - 'A' + 1]++;
        
        int re = judge();
        
        if (re == 1) {
            printf("Inconsistency found after %d relations.",i);
            return 0;
        }
        
        if (ans.size() == n && !re) {
            printf("Sorted sequence determined after %d relations: ", i);
            
            while (ans.size()) {
                cout << (char)(ans.front() - 1 + 'A');
                ans.pop();
            }
            
            cout << ".";
            return 0;
        }
    }
    printf("Sorted sequence cannot be determined.");
    
    return 0;
}
