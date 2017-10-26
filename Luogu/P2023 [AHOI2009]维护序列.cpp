#include <iostream>
#include <cstdio>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

using namespace std;

long long n, m, p;

struct Node {
    long long add;
    long long mul;
    
    Node() {
        add = 0;
        mul = 1;
    }
} col[100000 << 2];

long long sum[100000 << 2];

void PushUP(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    sum[rt] %= p;
}

void PushDown(int rt, int m) {
    if (col[rt].mul != 1) {
        sum[rt << 1] *= col[rt].mul;
        sum[rt << 1 | 1] *= col[rt].mul;
        sum[rt << 1] %= p;
        sum[rt << 1 | 1] %= p;
        
        col[rt << 1].add *= col[rt].mul;
        col[rt << 1 | 1].add *= col[rt].mul;
        col[rt << 1].add %= p;
        col[rt << 1 | 1].add %= p;
        
        col[rt << 1].mul *= col[rt].mul;
        col[rt << 1 | 1].mul *= col[rt].mul;
        col[rt << 1].mul %= p;
        col[rt << 1 | 1].mul %= p;
        
        col[rt].mul = 1;
    }
    
    if (col[rt].add) {
        sum[rt << 1] += (m - (m >> 1)) * col[rt].add;
        sum[rt << 1 | 1] += (m >> 1) * col[rt].add;
        sum[rt << 1] %= p;
        sum[rt << 1 | 1] %= p;
        
        col[rt << 1].add += col[rt].add;
        col[rt << 1 | 1].add += col[rt].add;
        col[rt << 1].add %= p;
        col[rt << 1 | 1].add %= p;
        
        col[rt].add = 0;
    }
}

void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%lld", &sum[rt]);
        sum[rt] %= p;
        return;
    }
    
    int m = (l + r) >> 1;
    
    build(lson);
    build(rson);
    
    PushUP(rt);
}

void mul_update(int L, int R, long long mul, int l, int r, int rt) {
    if (L <= l && r <= R) {
        col[rt].mul *= mul;
        col[rt].mul %= p;
        
        col[rt].add *= mul;
        col[rt].add %= p;
        
        sum[rt] *= mul;
        sum[rt] %= p;
        return;
    }
    
    PushDown(rt, r - l + 1);
    
    int m = (l + r) >> 1;
    
    if (L <= m)
        mul_update(L, R, mul, lson);
    
    if (m < R)
        mul_update(L, R, mul, rson);
        
    PushUP(rt);
}

void add_update(int L, int R, long long add, int l, int r, int rt) {
    if (L <= l && r <= R) {
        col[rt].add += add;
        col[rt].add %= p;
        
        sum[rt] +=  (r - l + 1) * add;
        sum[rt] %= p;
        
        return;
    }
    
    PushDown(rt, r - l + 1);
    
    int m = (l + r) >> 1;
    
    if (L <= m)
        add_update(L, R, add, lson);
    
    if (m < R)
        add_update(L, R, add, rson);
    
    PushUP(rt);
}

long long query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return (sum[rt] % p);
        
    PushDown(rt, r - l + 1);
    
    int m = (l + r) >> 1;
    long long sum = 0;
    
    if (L <= m)
        sum = query(L, R, lson);
    
    if (m < R)
        sum += query(L, R, rson);
        
    return (sum % p);
}

int main() {
    freopen("in.txt", "r", stdin);
    
    scanf("%lld%lld", &n, &p);
    
    build(root);
    
    scanf("%lld", &m);
    
    long long a, b, c, d;
    
    while (m--) {
        scanf("%lld%lld%lld", &a, &b, &c);
        
        if (a == 1) {
            scanf("%lld", &d);
            
            mul_update(b, c, d, root);
        } else if (a == 2) {
            scanf("%lld", &d);
            
            add_update(b, c, d, root);
        } else
            printf("%lld\n", query(b, c, root));
    }
    
    return 0;
}
