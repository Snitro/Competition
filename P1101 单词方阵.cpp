#include<iostream>
using namespace std;
char yizhong[7] = {'y','i','z','h','o','n','g'};
char all[100][100];
int lu[100][2];
char end[100][100];
int h;
int x[8] = {1,-1,0,0,1,1,-1,-1},
	y[8] = {0,0,1,-1,1,-1,1,-1};
void sou(int,int,int,int);
int main(){
	cin>>h;
	char in;
	for(int a = 0;a<h;a++){
		for(int b = 0;b<h;b++){
			end[a][b] = '*';
		}
	}
	for(int a = 0;a<h;a++)
		for(int b = 0;b<h;b++){
			cin>>all[a][b];
		}
	for(int a = 0;a<h;a++){
		for(int b = 0;b<h;b++){
			for(int c = 0;c<8;c++){
				sou(a,b,0,c);
			}	
		}
	}
	for(int a = 0;a<h;a++){
		for(int b = 0;b<h;b++){
			cout<<end[a][b];
		}
		
		cout<<endl;
	}
	return 0;
}
void sou(int ty,int tx,int c,int flg){
	if(c == 7){
		for(int a = 0;a<7;a++){
			end[lu[a][1]][lu[a][0]] = all[lu[a][1]][lu[a][0]];
		}
	}
	if(all[ty][tx] == yizhong[c]&&c<7){
		int y1 = ty+y[flg];
		int x1 = tx+x[flg];
		if(y1<=h&&y1>=-1&&x1<=h&&x1>=-1){
			lu[c][0] = tx;
			lu[c][1] = ty;
			sou(y1,x1,c+1,flg);
		}
	}
}
