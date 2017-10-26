#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int x[10005];
int now[10005];
int data[10005][3];
int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		scanf("%d%d%d",&data[i][0],&data[i][1],&data[i][2]);
	for(int i = 1;i <= n;i++)
		x[i] = 1;
	for(int i = 1;i <= n;i++)
		now[i] = data[i][0] + data[i][1] + data[i][2];
	for(int i = 1;i <= m;i++){
		/*
		cout << endl;
		for(int j = 1;j <= n;j++)
			cout << now[j] << " ";
		cout << endl;
		*/
		int Min = 1;
		for(int j = 2;j <= n;j++)
			if(now[j] < now[Min])
				Min = j;
		cout << now[Min] << " ";
		x[Min]++;
//		cout << endl << x[Min] << endl;
		now[Min] = data[Min][0] * x[Min] * x[Min] + data[Min][1] * x[Min] + data[Min][2];
	}
	return 0;
}
