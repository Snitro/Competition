#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int happy[6005];
int head[6005];
int in[6005];
int Go[6005];
int NotGo[6005];
struct Edge{
	int next;
	int to;
}edge[6005];
int edge_len = 0;
void add(int from,int to){
	edge_len++;
	edge[edge_len].next = head[from];
	edge[edge_len].to = to;
	head[from] = edge_len;
}
void judge(int id){
	if(Go[id] != -1 && NotGo[id] != -1)
		return;
	Go[id] = 0;
	NotGo[id] = 0;
	for(int i = head[id];i != 0;i = edge[i].next){
		judge(edge[i].to);
		NotGo[id] += max(Go[edge[i].to],NotGo[edge[i].to]);
		Go[id] += NotGo[edge[i].to];
	}
	Go[id] += happy[id];
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> n;
	for(int i = 1;i <= n;i++)
		scanf("%d",&happy[i]);
	int a,b;
	for(int i = 1;i < n;i++){
		scanf("%d%d",&a,&b);
		in[a]++;
		add(b,a);
	}
	int Head = 0;
	for(int i = 1;i <= n;i++)
		if(!in[i]){
			Head = i;
			break;
		}
	memset(Go,-1,sizeof(Go));
	memset(NotGo,-1,sizeof(NotGo));
	judge(Head);
	/*
	for(int i = 1;i <= n;i++)
		cout << Go[i] << " ";
	cout << endl;
	for(int i = 1;i <= n;i++)
		cout << NotGo[i] << " ";
	*/
	cout << max(Go[Head],NotGo[Head]);
	return 0;
}
