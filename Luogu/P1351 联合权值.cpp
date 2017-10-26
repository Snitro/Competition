#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
struct set;
long long ans = 0;
int head[1000000];
int dis[1000000];
int i = 0;
int n;
long long MAX = -1;
long long data[1000000];
struct edge {
	int next;
	int to;
} edge[1000000];
void add(int from,int to) {
	edge[++i].next = head[from];
	edge[i].to = to;
	head[from] = i;
}
int main() {
	freopen("in.txt","r",stdin);
	cin >> n ;
	int u,v;
	for(int i = 1; i < n; i++) {
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d",&data[i]);
		data[i] = data[i] % 10007;
	}
	for(int i = 1;i <= n;i++){
		long long sum = 0;
		long long MAX1 = -1,MAX2 = -1;
		for(int j = head[i];j != 0;j = edge[j].next){
			if(data[edge[j].to] > MAX1){
				MAX2 = MAX1;
				MAX1 = data[edge[j].to];
			}else if(data[edge[j].to] > MAX2)
				MAX2 = data[edge[j].to];
	        ans = (ans + sum * data[edge[j].to]) % 10007;
	        sum = (sum + data[edge[j].to]) % 10007;
	        MAX = max(MAX,MAX1 * MAX2);
		}
	}
	cout << MAX << " " << (ans * 2) % 10007;
}
