#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
struct set;
queue<set> que;
int n,p,c,m;//n为小朋友数   p关系数   C小朋友   吃m秒。
int head[5000005];
bool has[5000005];
int dis[5000005];
int i = 0;
struct edge{
	int next;
	int to;
}edge[5000005];
struct set{
	int id;
	set(int id){
		this -> id = id;
	}
};
void add(int from,int to){
	edge[++i].next = head[from];
	edge[i].to = to;
	head[from] = i;
}
int getfarthest(){
	int q = 0;
	set a = *(new set(c));
	que.push(a);
	has[c] = true;
	dis[c] = 0;
	while(!que.empty()){
		a = que.front();
		for(int i = head[a.id];i != 0;i = edge[i].next){
			if(dis[edge[i].to] > dis[a.id] + 1){
				dis[edge[i].to] = dis[a.id] + 1;
				if(!has[edge[i].to]){
					has[edge[i].to] = true;
					que.push(*(new set(edge[i].to)));
				}
			}
		}
		que.pop();
		has[a.id] = false;
	}
	for(int i = 1;i <= n;i++){
		if(dis[i] > q){
			q = dis[i];
		}
	}
	return q;
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> p >> c >> m;
	memset(dis,127/3,sizeof(dis));
	int a,b;
	for(int i = 1;i <= p;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	cout << getfarthest() + m + 1;
}
