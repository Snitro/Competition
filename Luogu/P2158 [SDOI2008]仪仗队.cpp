#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n,phi[40005];

void phi_table(){
	phi[1] = 1;
	for (int i = 2; i<= n; i++)
		if (!phi[i])
			for (int j = i; j <= n; j += i) {
				if (!phi[j])
					phi[j] = j;
				phi[j] = double(phi[j]) / i * (i - 1);
			}
}

int main(){
	freopen("in.txt","r",stdin);
	cin >> n;
	phi_table();
	long long ans = 0;
	for (int i = 2; i <= n; i++)
		ans += phi[i - 1];
	cout << ans * 2 + 1;
	return 0;
}
