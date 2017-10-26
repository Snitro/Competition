#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int value[40010];
int head[40010];
int edge_len = 1;
long long F[40010];
struct Edge{
	int next;
	int to;
	bool flg;
	Edge(){
		flg = true;
	}
}edge[40010];
void DP(int id){
	if(F[id] <= 2147483647)
		return;
	F[id] = value[id];
	for(int i = head[id];i != 0;i = edge[i].next){
		if(edge[i].flg){
			DP(edge[i].to);
			if(F[edge[i].to] > 0)
				F[id] += F[edge[i].to];
		}
	}
}
void add(int from,int to){
	edge[edge_len].to = to;
	edge[edge_len].next = head[from];
	head[from] = edge_len;
	edge_len++;
}
void cut(int id,int father){
	for(int i = head[id];i != 0;i = edge[i].next)
		if(edge[i].to == father)
			edge[i].flg = false;
		else
			cut(edge[i].to,id);
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> n;
	for(int i = 1;i <= n;i++)
		scanf("%d",&value[i]);
	int MAX = 1;
	for(int i = 2;i <= n;i++)
		if(value[i] > value[MAX])
			MAX = i;
	int a,b;
	for(int i = 1;i < n;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	cut(MAX,-1);
	for(int i = 1;i <= n;i++)
		F[i] = 9999999999;
	DP(MAX);
	cout << F[MAX];
	return 0;
}
