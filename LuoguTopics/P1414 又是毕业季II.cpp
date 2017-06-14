#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int d[1000001];
int main() {
	freopen("in.txt","r",stdin);
    int n, p = 0;
    cin >> n;
    for (int i = 1,a; i <= n; i++) {
        cin >> a;
        p = max(p, a);
        int x = sqrt(a + 0.5);
        for (int j = 1; j <= x; j++) {
            if (a % j == 0) {
                d[j]++;
                if (j * j != a)
					d[a / j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        while (d[p] < i)
			p--;
        cout << p << endl;
    }
}
