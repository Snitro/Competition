#include<iostream>
#include<cstdio>
using namespace std;
long long n,x;//nºÃÓÑ x¸öÒ© 
long long dp[10005];
struct vs{
    int lose;
    int win;
    int need;
}vs[10005];
int main(){
    freopen("in.txt","r",stdin);
    cin >> n >> x; 
    for(int i = 1;i <= n;i++)
        cin >> vs[i].lose >> vs[i].win >> vs[i].need;
    for(int i = 1;i <= n;i++){
        for(int j = x;j >= 0;j--){
            long long  a = dp[j] + vs[i].lose;
            if(j >= vs[i].need)
                a = max(a,dp[j - vs[i].need] + vs[i].win);
            dp[j] = a;
        }
    }
    cout << dp[x] * 5;
}
