#include<iostream>
#include<cstdio>
using namespace std;
int n,m;//nºáÐÐ mÊúÁÐ 
int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> m;
	long long ans1 = 0;
	long long ans2 = 0; 
	for(int i = 1;i <= min(n,m);i++)
		ans1 += (n - i + 1) * (m - i + 1);
	for(int x = 1;x <= m;x++)
		for(int y = 1;y <= n;y++)
			if(x != y)
				ans2 += (m - x + 1) * (n - y + 1);
	cout << ans1 << " " << ans2;
}
