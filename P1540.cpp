#include<iostream>
#include<cstdio>
using namespace std;
int in[1005];
int lie[10000];
int f,e;
int m,n,total;
void add(int i){
	if(e - f + 1 <= m){
		lie[e++] = i;
	}else{
		f++;
		lie[e++] = i;
	}
}
bool find(int n){
	for(int a = f;a < e;a++){
		if(n == lie[a]){
			return true;
		}
	}
	return false;
}
int main(){
//	freopen("in.txt","r",stdin);
	cin >> m >> n;
	for(int i = 1;i <= n;i++)
		cin >> in[i];
	for(int i = 1;i <= n;i++){
		if(!find(in[i])){
			total++;
			add(in[i]);
		}
		/*
		for(int a = f;a < e;a++){
			cout << lie[a] << " " ;
		}
		cout <<endl;
		*/
	}
	cout << total;
}
