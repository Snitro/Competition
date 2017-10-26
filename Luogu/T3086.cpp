#include<iostream>
#include<cstdio>
using namespace std;
int m,n;
int ans[10000];
struct stor{
    int w;
    int c;
} ha[100000];
int main(){
    //freopen("in.txt","r",stdin);
    cin >> m >> n;
    for(int i = 1;i <= n;i++)
        cin >> ha[i].w >> ha[i].c;
    for(int i = 1;i <= n;i++){
        for(int a = m;a >= 1;a--){
            int b = ha[i].c + ans[a - ha[i].w];
            if(a - ha[i].w < 0)
                b = 0;
            ans[a] = max(ans[a],b);
        }
    }
    cout << ans[m];
}
