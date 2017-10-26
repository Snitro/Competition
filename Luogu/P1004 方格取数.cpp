#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int map[20][20];
int map1[20][20];
int n = 0;
int ans = 0;
void search(int x,int y,int th){
	if(x > n || y > n)
		return;
	//cout << x << "  " << y << endl;
	if(x == n && y == n){
		for(int i = 0;i <= n;i++)
			for(int p = 0;p <= n;p++)
				map1[i][p] = map[i][p];
		/*
		for(int a = 1;a <= n;a++){
			for(int b = 1;b <= n;b++){
				cout <<  map1[b][a] << " ";
			}
			cout << endl;
		}
		*/
		for(int x = n;x >= 1;x--){
			for(int y = n;y >= 1;y--){
				map1[x][y] = max(map1[x+1][y],map1[x][y+1]) + map1[x][y];
			}
		}
		/*
		for(int a = 1;a <= n;a++){
			for(int b = 1;b <= n;b++){
				cout << setw(2) <<  map1[b][a] << " ";
			}
			cout << endl;
		}
		*/
		//cout << endl << endl; 
		ans = max(ans,map1[1][1] + th);
		//cout << "tod = " << map1[1][1]<< "   ans =  " << ans  << "  this =  " << th<< endl;
	}else {
		int i = map[x][y];
		map[x][y] = 0;
		search(x + 1,y,th + i);
		search(x,y + 1,th + i);
		map[x][y] = i;
	}
	
}
int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin >> n;
	int a,b,c;
	while(true){
		cin >>a >> b >> c;
	   	if(a == 0 && b == 0 && c == 0)
			break;
		map[b][a] = c;
	}
	search(1,1,0);
	cout << ans;
}
