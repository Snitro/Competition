#include<iostream>
#include<cstdio>
#include<sstream>
#include<cstring>
using namespace std;
int color[30];
bool t[30][30];
int n,i1,i2;
stringstream st;
string in;
int main(){
	freopen("in.txt","r",stdin);
	cin >> n;
	for(int a = 1;a <= n;a++){
		getline(cin,in);
		st << in;
		st >> i1;
		while(st >> i2){
			t[i1][i2] = true;
			t[i2][i1] = true;
		}
	}
	for(int a = 1;a <= n;a++){
		bool flg[5] = {false,false,false,false,false};
		for(int i = 1;i <= n;i ++)
			if(t[a][i])
				flg[color[i]] = true;
		for(int i = 1;i <= 4;i++)
			if(flg[i] == false){
				color[a] = i;
				break;
			}
	}
	for(int a = 1;a <= n;a++){
		cout << color[a] << " ";
	}
	return 0;
}
