#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
long long e,ans[4200],sum;
int g[4200][4200],a,b,start,du[4200],tot;
void dfs(int i){
    int j;
    for(j=1;j<=e;++j){
        if(g[i][j]>=1){
            g[i][j]--;
            g[j][i]--;
            dfs(j);
        }
    }
    ans[++sum]=i;
}
int main(){
    //freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int m;
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>a>>b;
        if(a>e)e=a;
        if(b>e)e=b;
        g[a][b]++;
        g[b][a]++;
        du[a]++;
        du[b]++;
    }
    start=1;
    for(int i=1;i<=e;++i){
        if(du[i]%2==1){
            start=i;
            break;
        }
    }
    sum=0;
    dfs(start);
    tot=1;
    while(ans[tot]!=0)tot++;
    tot--;
    for(int i=tot;i>=1;--i){
        cout<<ans[i]<<endl;
    }
    return 0;
}
