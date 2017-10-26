#include<iostream>
#include<cstdio>
#include<cmath> 
using namespace std;
int m;
int main(){
    freopen("in.txt", "r", stdin);
    cin >> m;
    double right;
    for (long long a = 1; a <= m / 2; a++) {
        right = 2 * m + a * a - a + 0.25;
        //解  b ^ 2 + b = right 的方程 
        right = sqrt(right) - 0.5;
        if ((int)right == right)
            printf("%lld %lld\n",a,(long long)right);
    }
    return 0;
}
