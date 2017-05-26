#include<iostream>
using namespace std;
int n,in[30][30];
int wx[4]{1,-1,0,0},
	wy[4]{0,0,1,-1};
void sou(int x,int y){
	if(in[y][x] == 0)
		in[y][x]  = -1;
	else
		return;
	int tx,ty;
	for(int a = 0;a<4;a++){
		tx = x + wx[a];
		ty = y + wy[a];
		if(tx>=0&&tx<n&&ty>=0&&ty<n)
			sou(tx,ty);
	}
}
int main(){
	cin>>n;
	for(int a = 0;a<n;a++)
		for(int b = 0;b<n;b++)
			cin>>in[a][b];
	for(int a = 0;a<n;a++){
		sou(0,a);
		sou(n-1,a);
		sou(a,0);
		sou(a,n-1);
	}
	for(int a = 0;a<n;a++){
		for(int b = 0;b<n;b++){
			if(in[a][b] == 0)
				cout<<2;
			else if(in[a][b] == -1)
				cout<<0;
			else
				cout<<1;
			cout<<" ";
		}
		cout<<endl;
	}	
}
