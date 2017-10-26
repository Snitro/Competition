#include <iostream> 
#include <cstdio>
#include <cstring>

#define max(a, b) ((a) >= (b) ? (a) : (b))
#define min(a, b) ((a) <= (b) ? (a) : (b))

using namespace std;

const long long maxn = 30000;

int n, m1, m2, size, ans = 999999999, tot, MAX_m, MAX_Data;

long long m[maxn], prime[maxn], datas[maxn], data;

bool notPrime[maxn];

inline long long read() {
    long long k = 0;
    int f = 1;
    char c = getchar();
    
    while (c > '9' || c < '0') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    
    while (c <= '9' && c >= '0') {
        k = k * 10 + c - '0';
        c = getchar();
    }
    
    return f * k;
}

void init() {
    for (long long i = 2; i < maxn; i++) {
        if (!notPrime[i])
            prime[++size] = i;
        for (int j = 1; j <= size && prime[j] * i <= maxn; j++) {
            notPrime[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void analyse(long long num, long long * res, int & MAX) {
    int i;
    
    for (i = 1; i <= size && num > 1 && prime[i] <= num; i++) {
        while (num % prime[i] == 0) {
            res[i]++;
            num /= prime[i];
        }
    }
    
    MAX = i;
}

int ceil(int a, int b) {
    a += b - 1;
    return a / b;
}

int main() {
    freopen("in.txt", "r", stdin);
    
    init();
    
    scanf("%d%d%d", &n, &m1, &m2);
    
    if (m1 == 1 || m2 == 0) {
        printf("0");
        return 0;
    }
    
    analyse(m1, m, MAX_m);
    
    for (int i = 1; i <= size; i++)
        m[i] *= m2;
        
    for (int i = 1; i <= n; i++) {
        data = read();
        
        tot = -1;
        memset(datas, 0, sizeof(datas));
        
        analyse(data, datas, MAX_Data);
        
        MAX_Data = MAX_Data >= MAX_m ? min(MAX_m, MAX_Data) : -1;
        
        for (int j = 1; j <= MAX_Data; j++)
            if (m[j]) {
                if (datas[j])
                    tot = max(tot, ceil(m[j], datas[j]));
                else {
                    tot = -1;
                    break;
                }
            }
        
        if (tot == -1)
            continue;
        
        if (tot < ans)
            ans = tot;
    }
    
    printf("%d", ans == 999999999 ? -1 : ans);
    
    return 0;
}
