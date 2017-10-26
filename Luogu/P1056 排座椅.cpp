#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int m,n,k,l,d;

struct data {
	int id;
	int n;
};

data M[1005],//ÐÐ 
	N[1005];//ÁÐ 

bool cmp(data a, data b){
	return a.n > b.n;
}

bool cmp2(data a, data b){
	return a.id < b.id;
}

int main(){
	freopen("in.txt","r",stdin);
	cin >> m >> n >> k >> l >> d;
	for (int i = 1; i < m; i++)
		M[i].id = i;
	for (int i = 1; i < n; i++)
		N[i].id = i;
	int x,y,p,q;
	for (int i = 1; i <= d; i++) {
		scanf("%d%d%d%d",&x,&y,&p,&q);
		if (x == p)
			N[min(y, q)].n++;
		else
			M[min(x, p)].n++;
	}
	sort(M + 1, M + m, cmp);
	sort(N + 1, N + n, cmp);
	sort(M + 1, M + k + 1, cmp2);
	sort(N + 1, N + l + 1, cmp2);
	for (int i = 1; i <= k; i++) 
		printf("%d ", M[i].id);
	cout << endl;
	for (int i = 1; i <= l; i++)
		printf("%d ", N[i].id);
	return 0;
}
