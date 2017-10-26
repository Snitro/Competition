#include<cstdio>
#include<iostream>
using namespace std;
int n,na,nb;
int A[205];
int B[205];
int ansA;
int ansB;
int idA = 1;
int idB = 1;
//1Ó® 0Æ½ -1Êä 
int judge(int a,int b){
    if(a == b)
        return 0;
    if(a == 0){
        if(b == 3 || b == 2)
            return 1;
    }else if(a == 1){
        if(b == 3 || b == 0)
            return 1;
    }else if(a == 2){
        if(b == 4 || b == 1)
            return 1;
    }else if(a == 3){
        if(b == 4 || b == 2)
            return 1;
    }else if(a == 4){
        if(b == 0 || b == 1)
            return 1;
    }
    return -1;
}
int main(){
//    freopen("rps.in","r",stdin);
//    freopen("rps.out","w",stdout);
    cin >> n >> na >> nb;
    for(int i = 1;i <= na;i++)
        scanf("%d",&A[i]);
    for(int i = 1;i <= nb;i++)
        scanf("%d",&B[i]);
    for(int i = 1;i <= n;i++){
        int ans = judge(A[idA],B[idB]);
        if(ans == 1)
            ansA++;
        if(ans == -1)
            ansB++;
        idA++;
        idB++;
        if(idA > na)
            idA = 1;
        if(idB > nb)
            idB = 1;
    }
    cout << ansA << " " << ansB;
    return 0;
}
