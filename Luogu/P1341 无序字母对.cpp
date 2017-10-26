#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

stack <int> ans;

int n;

int map[100][100];

bool show[100];

int du[100];

char getChar(int a) {
    if (a <= 26)
        return a - 1 + 'A';
    return a - 1 - 26 + 'a';
}

void search(int id) {
    for (int i = 1; i <= 52; i++) {
        if (map[id][i]) {
            map[id][i]--;
            map[i][id]--;
            
            search(i);
        }
    }
    
    ans.push(id);
}

int main() {
    freopen("in.txt", "r", stdin);
    
    cin >> n;
    
    string st;
    
    int b = 99;
    
    for (int i = 1; i <= n; i++) {
        cin >> st;
        
        if (st[0] >= 'a') {
            st[0] -= 'a';
            st[0] += 1 + 26;
        } else 
            st[0] = st[0] - 'A' + 1;
        
        if(st[1] >= 'a') {
            st[1] -= 'a';
            st[1] += 1 + 26;
        } else
            st[1] = st[1] - 'A' + 1;
        
        show[st[1]] = true;
        show[st[0]] = true;
        
        du[st[1]]++;
        du[st[0]]++;
        
        if (min(st[1], st[0]) < b)
            b = min(st[1], st[0]);
        
        map[st[1]][st[0]]++;
        map[st[0]][st[1]]++;
    }
    
    for (int i = 1; i <= 52; i++) {
        if (show[i] && du[i] % 2) {
            b = i;
            break;
        }
    }
    
    int cnt = 0;
    
    for (int i = 1; i <= 52; i++) {
    	if (show[i] && du[i] % 2)
    		cnt++;
	}
	
	if (cnt != 0 && cnt != 2) {
		cout << "No Solution";
        return 0;
	}
    
    search(b);
    
    int tot = 0;
    
    if (ans.size() != n + 1) {
        cout << "No Solution";
        return 0;
    }
    
    while (ans.size()) {
        cout << getChar(ans.top());
        ans.pop();
    }
    
    return 0;
}
