#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct set;
queue<set> que;
int n,p,c,m;//n为小朋友数   p关系数   C小朋友   吃m秒。
int head[5000005];
bool has[5000005];
int i = 0;
struct edge{
    int next;
    int to;
}edge[5000005];
struct set{
    int id;
    int n;
    set(int id,int n){
        this -> id = id;
        this -> n = n;
    }
};
void add(int from,int to){
    edge[++i].next = head[from];
    edge[i].to = to;
    head[from] = i;
}
int getfarthest(){
    int n = 0;
    set a = *(new set(c,0));
    que.push(a);
    has[c] = true;
    while(!que.empty()){
        a = que.front();
        if(a.n > n)
            n = a.n;
        for(int i = head[a.id];i != 0;i = edge[i].next){
            if(has[edge[i].to])
                continue;
            que.push(*(new set(edge[i].to,a.n + 1)));
            has[edge[i].to] = true;
        }
        que.pop();
        //has[a.id] = false;
    }
    return n;
}
int main(){
    freopen("in.txt","r",stdin);
    cin >> n >> p >> c >> m;
    int a,b;
    for(int i = 1;i <= p;i++){
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    cout << getfarthest() + m + 1;
}
