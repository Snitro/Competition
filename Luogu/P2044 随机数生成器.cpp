#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long m, a, c, f, n, g;

long long mul(long long a, long long b) {
	long long ret = 0;
	
	for (; b; b >>= 1) {
		if (b & 1)
			ret = (ret + a) % m;
		a = (a + a) % m;
	}
	
	return ret;
} 

struct Matrix {
	int x;
	int y;
	
	long long matrix[3][3];
	
	Matrix() {
		memset(matrix, 0, sizeof(matrix));
	}
	
	Matrix operator * (Matrix a) {
		Matrix ret;
		
		for (int i = 1; i <= y; i++)
			for (int j = 1; j <= a.x; j++)
				for (int k = 1; k <= x; k++) {
					ret.matrix[i][j] = (ret.matrix[i][j] % m + mul(matrix[i][k], a.matrix[k][j]) % m) % m;
				}
		
		ret.x = x;
		ret.y = y;
		
		return ret;
	}
} num, one;

Matrix pow (Matrix n, long long p) {
	Matrix ret = one;
	
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * n;
		n = n * n;
	}
	
	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%lld%lld%lld%lld%lld%lld", &m, &a, &c, &f, &n, &g);
	
	f %= m;
	c %= m; 
	
	num.x = num.y = 2;
	num.matrix[1][1] = a;
	num.matrix[2][1] = num.matrix[2][2] = 1;
	
	one.matrix[1][1] = one.matrix[2][2] = 1;
	one.x = one.y = 2;
	
	num = pow(num, n);
	
	printf("%lld", (mul(f, num.matrix[1][1]) + mul(c, num.matrix[2][1])) % m % g);
	
	return 0;
}
