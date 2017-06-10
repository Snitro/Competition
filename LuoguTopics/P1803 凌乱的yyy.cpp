#include<cstdio>  
#include<iostream>  
#include<algorithm> 
using namespace std;
int n,total;
/*
	贪心解决
	>先按结束时间升序排序
	>选择第一个任务
	>再依次判断开始时间是否与上一个已选任务冲突
	>如果没有则选择此任务
	>最后输出选择的任务数量
*/
struct node{
	int x;  
	int y;  
}all[1000001];  
bool cmp(const node a,const node b)  
{  
    if ((a.y<b.y) || ((a.y==b.y) && (a.x<b.x))) return true;  
    else return false;  
}  
int main(){
	cin>>n;
	for(int a = 0;a<n;a++){
		cin>>all[a].x>>all[a].y;
	}
	sort(all,all+n,cmp);  
	int end = -1;
	for(int a = 0;a<n;a++){
		if(all[a].x>=end){
			end = all[a].y;
			total++;
		}
	}
	cout<<total;
}
