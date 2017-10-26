#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,total;//n钱数m物品个数 
int f[65][32010];
int max(int a,int b,int c,int d,int e){
	int z[5] = {a,b,c,d,e};
	sort(z,z + 5);
	return z[4];
}
struct thing{
	int v;//价格 
	int m;//重要度 
	int f1v;
	int f1m;
	int f2v;
	int f2m;
	thing(){
		v = 0;
		m = 0;
		f1v = 0;
		f1m = 0;
		f2v = 0;
		f2m = 0;
	}
	void add(int v,int m){
		if(f1v == 0){
			f1v = v;
			f1m = m;
		} else {
			f2v = v;
			f2m = m;
		}
	}
} thing[65];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> n >> m;
	int v,p,q;
	for(int i = 1;i <= m;i++){
		cin >> v >> p >> q;
		if(q != 0){
			thing[q].add(v,p);
			total++;
		}else{
			thing[i].v = v;
			thing[i].m = p;
		}
	}
	for(int i = 1;i <= m;i++){
		if(thing[i].v == 0){
			for(int a = i + 1;a <= m;a++)
				if(thing[a].v != 0){
					thing[i] = thing[a];
					thing[a].v = 0;
					break;
				}
		}
	}
	m = m - total;
	int v1,v2,v3,v4,v5;
	for(int a = 1;a <=m;a++){
		for(int i = 1;i <= n;i++){
			v1 = v2 = v3 = v4 = v5 = 0;
			if(i - thing[a].v >= 0)
				v1 = f[a - 1][i - thing[a].v] + thing[a].v * thing[a].m;
			if(i - thing[a].v - thing[a].f1v >= 0){
				v2 = f[a - 1][i - thing[a].v - thing[a].f1v] + thing[a].v * thing[a].m + 
					thing[a].f1v * thing[a].f1m;
			}
			if(i - thing[a].v - thing[a].f2v >=0){
				v3 = f[a - 1][i - thing[a].v - thing[a].f2v] + thing[a].v * thing[a].m + 
					thing[a].f2v * thing[a].f2m;
			}
			if(i - thing[a].v - thing[a].f1v - thing[a].f2v >= 0){
				v4 = f[a - 1][i - thing[a].v - thing[a].f1v - thing[a].f2v] + thing[a].v * 
					thing[a].m + thing[a].f1v * thing[a].f1m + thing[a].f2v * thing[a].f2m;
			}
			v5 = f[a - 1][i];
			f[a][i] = max(v1,v2,v3,v4,v5);
		}
	}
	/*
	for(int i = 1;i <= m;i++){
		for(int a = 1;a <= n;a++)
			cout << a << ":" << f[i][a] << "     "; 
		cout << endl;
	}
	*/
	cout << f[m][n];
}
