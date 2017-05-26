#include<cstdio>
using namespace std;
int n,m;
int v[40010],num[15010];
int a[15010],b[15010],c[15010],d[15010];
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= m; i ++){
        scanf("%d",&v[i]);
        num[v[i]]++;
    }
    for(int t = 1; t * 9 < n; t++){
        int sum = 0;
        int va,vb,vc,vd;
        for(vd = t * 9 + 2; vd <= n; vd++){
            va = vd - 9 * t - 1;
            vb = vd - 7 * t - 1;
            vc = vd - t;
            sum += num[vb] * num[va];
            c[vc] += num[vd] * sum;
            d[vd] += num[vc] * sum; 
        }
        sum = 0;
        for(va = n - t * 9 - 1; va >= 1; va--){
            vb = va + 2 * t;
            vc = va + t * 8 + 1;
            vd = va + t * 9 + 1;
            sum += num[vc] * num[vd];
            a[va] += num[vb] * sum;
            b[vb] += num[va] * sum;
        }
    }
    for(int i = 1; i <= m; i++)
        printf("%d %d %d %d\n", a[v[i]],b[v[i]],c[v[i]],d[v[i]]);
}
