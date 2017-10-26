#include <iostream>
#include <cstdio>

using namespace std;

int a,b,k,n,m;

int com[1005][1005];

long long Com(int n,int m) {
	com[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		com[i][0] = 1;
		com[i][i] = 1;
		for (int j = 1; j < i; j++)
			com[i][j] = (com[i - 1][j] + com[i - 1][j - 1]) % 10007;
	}
	return com[m][n];
}

long long pow(int a,int b) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a % 10007;
	long long p = pow(a, b / 2);
	p = p % 10007;
	p = (p * p) % 10007;
	if (b % 2 == 0)
		return p;
	else
		return (p * a % 10007);
}

int main() {
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	cin >> a >> b >> k >> n >> m;
	long long ans = Com(m, k);
	ans *= (pow(a, n) * pow(b, m)) % 10007;
	ans = ans % 10007;
	cout << ans << endl;
	return 0;
}
