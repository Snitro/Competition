#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;//Ô²µÄ¸öÊý 
struct yuan{
	int x;
	int y;
	int r;
}yuan[1000];
double getR(int x1,int y1,int x2,int y2){
	return sqrt(fabs(x1 - x2) * fabs(x1 - x2) + fabs(y1 - y2) * fabs(y1 - y2));
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> yuan[i].x;
	for(int i = 0;i < n;i++)
		cin >> yuan[i].y;
	for(int i = 0;i < n;i++)
		cin >> yuan[i].r;
	int x1,x2,y1,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(getR(x1,y1,yuan[i].x,yuan[i].y) < yuan[i].r != getR(x2,y2,yuan[i].x,yuan[i].y) < yuan[i].r)
			ans++;
	}
	cout << ans;
}
