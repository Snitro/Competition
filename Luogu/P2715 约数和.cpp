#include <iostream>
#include <cstdio>

#define mod 9901
#define abs(x) ((x) >= 0 ? (x) : (-(x)))

using namespace std;

long long ans = 1;

long long a, b;

long long prime[4000000], Pow[4000000], size;

bool isprime[50000005];

void init() {
    for(int i = 2; i * i <= a; ++i) {
        if(!(a % i)) {
            prime[++size]=i;
            while(!(a % i)) {
                a /= i;
                Pow[size]++;
            }
        }
    }
    
    if(a != 1){
        prime[++size] = a;
        Pow[size]=1;
    }
    
    for (int i = 1; i <= size; i++)
        Pow[i] *= b;
}

long long pow(long long a, long long b) {
    long long ret = 1;
    
    for (; b; b >>= 1) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
    }
    
    return ret;
}

long long sum(long long p, long long c) {
    if (c == 0)
        return 1;
    else if (c == 1)
        return (1 + p) % mod;
        
    if (c % 2)
        return ((pow(p, (c + 1) / 2)  + 1) * sum(p, (c - 1) / 2)) % mod;
    else
        return ((pow(p, c / 2) + 1) * sum(p, c / 2 - 1) % mod + pow(p, c)) % mod;
} 

void count() {
    for(int i = 1;i <= size; i++) {
        if (Pow[i])
            ans = ans * sum(prime[i], Pow[i]) % mod;
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    
    scanf("%lld%lld", &a, &b);
    
    init();
    
    count();
    
    printf("%lld", ans);
    
    return 0;
}
