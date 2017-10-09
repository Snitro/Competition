#include <iostream>
#include <cstdio>

using namespace std;

long long n, m, l;

long long pow(long long a, long long b, long long mod){
    long long ret = 1;
    
    for (; b; b >>= 1) {
        if(b & 1)
            ret = (ret * a) % mod;
        
        a = (a * a) % mod;
    }
    
    return ret;
}

void ex_gcd(long long a, long long b, long long & d, long long & x, long long & y) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
    } else {
        ex_gcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    
    scanf("%lld%lld%lld", &n, &m, &l);
    
    n++;
    
    long long x, y, d;
     
    ex_gcd(pow(2, m, n), n, d, x, y);
    
    x = (x % n + n) % n;
    
    if (x == 0)
        x = n;
    
    printf("%lld", (l / d) * x % n);
    
    return 0;
}
