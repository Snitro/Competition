#include<cstdio>  
#include<iostream>  
#include<algorithm> 
using namespace std;
/*
	将数据从大到小排序
	如果最大的加上最小的大于要求最大要求价格
		则此最大价格物品单独分为一组
	如果最大的加上最小的小于或等于最大要求价格 
		由于一组最多分由两个物品
		则此最大的和最小的一起分为一组 
*/
int n,biggest,end;
struct in{
    int in;  
    int id;  
}all[1000001];
bool cmp(const in a,const in b)  
{  
    if (a.in>b.in) return true;  
    else return false;  
}    
int main(){
    cin>>biggest>>n;
    for(int a = 0;a < n;a++){
        cin>>all[a].in;
        all[a].id = a;
    }
    sort(all,all+n,cmp);
    int last = n-1;
    for(int a = 0;a<=last;a++){
        if(all[a].in+all[last].in>biggest){
            end++;
        }else{
            end++;
            last--;
        }
    }
    cout<<end;
}
