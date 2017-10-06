#include <iostream>
#include <cstdio>
#include <cstring>

#define mod 1000000007

using namespace std;

long long n, k;

struct Matrix {
    long long mat[105][105];
    int h, l;
    
    Matrix() {
        memset(mat, 0, sizeof(mat));
    }
    
    Matrix operator * (Matrix a) {
        Matrix ret;
        
        for (int i = 1; i <= this -> h; i++)
            for (int j = 1; j <= a.l; j++)
                for (int k = 1; k <= this -> l; k++)
                    ret.mat[i][j] = (ret.mat[i][j] + (mat[i][k] * a.mat[k][j]) % mod) % mod;
        
        ret.h = h;
        ret.l = a.l;
            
        return ret;
    }
} Begin, Zero;

Matrix pow(long long k) {
    Matrix b = Zero;
    
    for (; k; k >>= 1) {
    	if (k & 1)
    		b = b * Begin;
    	Begin = Begin * Begin;
	}
	return b;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++)
        Zero.mat[i][i] = 1;
    Zero.h = Zero.l = n;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        	scanf("%lld", &Begin.mat[i][j]);
        
    Begin.h = Begin.l = n;
    
    Matrix ret = pow(k);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << ret.mat[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}

