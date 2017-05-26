#include<iostream>
using namespace std;
int n,m,t,sx,sy,fx,fy,total,mi[1000][5];
int wx[4]{1,-1,0,0},
	wy[4]{0,0,1,-1};
void sou(int x,int y){
	if(x == fx&&y == fy){
		total++;
		return;
	}
	int tx,ty;
	for(int a = 0;a<4;a++){
		tx = x + wx[a];
		ty = y + wy[a];
		if(mi[ty][tx] == 0&&tx>=0&&tx<m&&ty>=0&&ty<n){
			mi[y][x] = -1;
			sou(tx,ty);
			mi[y][x] = 0;
		}
	}
}
int main(){
	int ix,iy;
	cin>>n>>m>>t>>sx>>sy>>fx>>fy;
	fx--;
	fy--;
	for(int a = 0;a<t;a++){
		cin>>ix>>iy;
		mi[iy-1][ix-1] = 1;
	}
	sou(sx-1,sy-1);
	cout<<total;
}
