#include <iostream> 
#include <cstdio>
#include <cstring>

using namespace std;

long long n, m;

struct Matrix {
	long long mat[5][5];
	int h, l;
	
	Matrix() {
		memset(mat, 0, sizeof(mat));
	}
	
	Matrix operator * (Matrix a) const {
		Matrix ret;
		
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= a.l; j++)
				for (int k = 1; k <= l; k++)
					ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * a.mat[k][j]) % m;
		
		ret.h = h;
		ret.l = a.l;
			
		return ret;
	}
} Begin, one;

Matrix pow(Matrix a, long long num) {
	for (; num; num >>= 1) {
		if (num & 1)
			one = one * a;
		a = a * a;
	}
	return one;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%lld%lld", &Begin.mat[1][1], &Begin.mat[1][2]);
	Begin.mat[2][1] = 1;
	
	one.mat[1][1] = one.mat[2][2] = 1;
	one.h = one.l = Begin.h = Begin.l = 2;
	
	int a1, a2;
	
	scanf("%d%d%lld%lld", &a1, &a2, &n, &m);
	
	Matrix Ans = pow(Begin, n - 2) ;
	
	printf("%lld", (Ans.mat[1][1] * a2 % m + Ans.mat[1][2] * a1 % m) % m);
}
