#include<iostream>
#include<cstdio>
using namespace std;
int n,s;//n节点总数 
struct tr{
    int con;
    int fa;
    int ch;
}tree[100005];
int root[100005];
int ans;
int main(){
    //freopen("in.txt","r",stdin);
    cin >> n >> s;
    for(int i = 1;i <= n;i++)
        cin >> tree[i].con;
    for(int i = 1;i < n;i++){
        int x,y;
        cin >> x >> y;
        tree[x].ch = y;
        tree[y].fa = x;
    }
    int rf = 1;
    for(int i = 1;i <= n;i++){
        tr t = tree[i];
        int a = 0;
        while(true){
            a += t.con;
            if(a == s){
                ans++;
                break;
            }
            if(a > s)
                break;
            if(t.fa == 0)
                break;
            else
                t = tree[t.fa];
        }
    }
    cout << ans;
}
