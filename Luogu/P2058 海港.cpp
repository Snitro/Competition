#include<queue>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n;
struct da{
    int t;
    int n;
    int a[105];
}data[100005];
int flg[100005];
queue <da> lie;
int ans = 0;
void push(da data){
    lie.push(data);
    for(int i = 1;i <= data.n;i++){
        if(flg[data.a[i]] == 0){
            ans ++;
        }
        flg[data.a[i]]++;
    }
}
void pop(){
    da a = lie.front();
    lie.pop();
    for(int i = 1;i <= a.n;i++){
        flg[a.a[i]]--;
        if(flg[a.a[i]] == 0){
            ans--;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d%d",&data[i].t,&data[i].n);
        for(int x = 1;x <= data[i].n;x++){
            scanf("%d",&data[i].a[x]);
        }
        push(data[i]);
        da a = lie.front();
        while(a.t + 86400 <=  data[i].t){
            pop();
            a = lie.front();
        }
        a = data[i];
        cout << ans << endl;
    }
}
