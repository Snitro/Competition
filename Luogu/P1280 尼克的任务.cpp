#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,k;//   n 工作时间   k  任务总数
int F[10005];
struct Job{
    int begin;
    int need;
    int end;
}job[10005];
int main(){
    freopen("in.txt","r",stdin);
    cin >> n >> k;
    for(int i = 1;i <= k;i++){
        scanf("%d%d",&job[i].begin,&job[i].need);
        job[i].end = job[i].begin + job[i].need;
    }
    F[n] = 0;
    for(int i = n;i >= 1;i--){
        if(job[k].begin == i){
            F[i] = n + 1;
            for(int j = k;job[j].begin == i;j--){
                if(F[i] == 0){
                    F[i] = F[job[j].end] + job[j].need;
                }
                else
                    F[i] = min(F[i],F[job[j].end] + job[j].need);
                k--;
            }
        }else
            F[i] = F[i + 1];
    }
    /*
    for(int i = 1;i <= n;i++)
        cout << F[i] << " ";
    */
    cout << n - F[1] ;
}
