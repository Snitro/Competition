#include <iostream>
#include <cstdio>
#include <cstring>

#define mod 1000000007

using namespace std;

int n;

struct Matrix {
	long long mat[5][5];
	int h, l;
	
	Matrix() {
		memset(mat, 0, sizeof(mat));
	}
	
	Matrix operator * (Matrix a) {
		Matrix ret;
		
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= a.l; j++)
				for (int k = 1; k <= l; k++)
					ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * a.mat[k][j]) % mod;
		
		ret.h = h;
		ret.l = a.l;
			
		return ret;
	}
} Zero, Begin;

Matrix pow(Matrix a, int num) {
	if (num == 1)
		return a;
	else if (num == 0)
		return Zero;
	
	Matrix ret = pow(a, num / 2);
	
	if (num % 2)
		return ret * ret * a;
	return ret * ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	Zero.mat[1][1] = Zero.mat[2][2] = Zero.mat[3][3] = 1;
	Zero.h = Zero.l = 3;
	
	Begin.h = Begin.l = 3;
	Begin.mat[1][3] = Begin.mat[2][1] = Begin.mat[3][2] = Begin.mat[3][3] = 1;
	
	int t;
	scanf("%d", &t);
	
	Matrix ret = Begin * Begin * Begin * Begin * Begin;
	
	while (t--) {
		scanf("%d", &n);
		
		ret = pow(Begin, n - 1);
		
		printf("%lld\n", (ret.mat[1][1] + ret.mat[2][1] + ret.mat[3][1]) % mod);
	}
	
	return 0;
}
