#include<iostream>
#include<cstdio>
using namespace std;
int color[100005];
int number[100005];
int sum[2][100001];
int d[2][100001];
int n,m;
long long ans;
int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> number[i];
	for(int i = 1;i <= n;i++)
		cin >> color[i];
	for(int i = 1;i <= n;i++){
		sum[i % 2][color[i]] += number[i];
    	sum[i % 2][color[i]] %= 10007;
    	d[i % 2][color[i]]++;
	}
	for (int i=1;i<=n;i++){
        ans += i % 10007 * ((sum[i % 2][color[i]] + (d[i % 2][color[i]] - 2)
			% 10007 * number[i] + 10007) % 10007);
        ans %= 10007;        
    }
	cout << ans;
}
