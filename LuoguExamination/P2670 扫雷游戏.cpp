#include<cstdio>
#include<iostream>
using namespace std;
int n,m;//行数和列数
int map[105][105];
int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> m;
	char a;
	for(int y = 1;y <= n;y++)
		for(int x = 1;x <= m;x++){
			cin >> a;
			if(a == '*')
				a = 1;
			else
				a = 0;
			map[x][y] = a;
		}
	for(int y = 1;y <= n;y++){
		for(int x = 1;x <= m;x++){
			if(map[x][y] == 1){
				cout << '*';
			}else{
				int total = 0;
				total += map[x - 1][y - 1] + map[x - 1][y] + map[x - 1][y + 1] + map[x][y - 1] +
					map[x][y + 1] + map[x + 1][y - 1] + map[x + 1][y] + map[x + 1][y + 1];
				cout << total;
			}
		}
		cout << endl;
	}
}
