#include<iostream>
using namespace std;
int n,x,y,id;
struct area{
	void in(){
		cin >> lx >> uy >> rx >> oy;
		rx += lx;
		oy += uy;
	}
	int lx,rx,uy,oy;
} area[10005];
int main(){
	cin >> n;
	for(int i = 1;i <=n;i++)
		area[i].in();
	cin >> x >> y;
	for(int i = 1;i <= n;i++){
		if(area[i].lx <= x && area[i].rx >= x
			&& area[i].oy >= y && area[i].uy <= y)
				id = i;
	}
	cout << id;
}
