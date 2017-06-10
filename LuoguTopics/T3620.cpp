#include<iostream>
#include<cstring>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<queue>
using namespace std;
int m,n;//开通了 M 条单程巴士线路，总共有 N 个车站
string s;
int map[505][505];
bool has[505];
struct set{
	int id;
	int n;
};
struct car{
	int i;
	int map[505];
	car(){
		i = 0;
	}
	int have(int a){
		for(int b = 0;b < i;b++)
			if(map[b] == a)
				return b;
		return -1;
	}
}car[105];
queue<set> lie;
void search(){
	has[1] = true;
	set a;
	a.id = 1;
	a.n = 0;
	lie.push(a);
	while(lie.size()){
		set i = lie.front();
		//cout << i.id << endl;
		if(i.id == n){
			cout << i.n - 1;
			exit(0);
		}
		for(int p = 0;p < m;p++){
			int b = car[p].have(i.id);
			if(b != -1){
				set q;
				for(int j = b + 1;j < car[p].i;j++){
					if(!has[car[p].map[j]]){
						q.id = car[p].map[j];
						q.n = i.n + 1;
						lie.push(q);
						has[car[p].map[j]] = true;
					}
				}
			}
		}
		lie.pop();
	}
}
int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin >> m >> n;
	getline(cin, s);
	for(int i = 0;i < m;i++){
		getline(cin, s);
		stringstream st;
		st << s;
		int a;
		while(st >> a){
			car[i].map[car[i].i++] = a;
		}
	}
	search();
	cout << "NO";
}
