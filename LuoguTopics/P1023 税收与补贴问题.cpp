#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct data {
    int a;
    int b;
} small[500], big[500];
int sl,bl;

double MAX = 999999999,MIN = -999999999;

int e;
int expect;

int beyond;

void getMAX(){
    for (int i = 1; i <= sl; i++) {
        double tMAX = (expect - small[1].a) * e - (small[i].a - small[1].a) * small[i].b;
        tMAX = tMAX / (small[i].b - e);
        MAX = min(MAX, tMAX);
    }
}

void getMIN(){
    for (int i = 1;i <= bl;i++) {
        double tMIN = (big[i].a - small[1].a) * big[i].b - (expect - small[1].a) * e;
        tMIN = tMIN / (e - big[i].b);
        MIN = max(MIN, tMIN);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> expect;
    int a,b;
    while (true) {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        if (a < expect) {
            sl++;
            small[sl].a = a;
            small[sl].b = b;
        } else if (a > expect) {
            bl++;
            big[bl].a = a;
            big[bl].b = b;
        } else {
            e = b;
        }
    }
    cin >> beyond;
    if (e == 0)
        e = small[sl].b - (expect - small[sl].a) * beyond;
    if (small[sl].a != expect - 1) {
        sl++;
        small[sl].a = expect - 1;
        small[sl].b = e + beyond;
    }
    bl++;
    if (bl == 1) {
        big[bl].a = expect + 1;
        big[bl].b = e - beyond;
    } else {
        big[bl].a = big[bl - 1].a + 1;
        big[bl].b = big[bl - 1].b - beyond;
    }
    getMAX();
    getMIN();
    //MIN++;
    //MAX--;
    //cout << MIN << " " << MAX << endl;
    MIN = ceil(MIN);
   	MAX = floor(MAX);
    if (MIN > MAX) 
        cout << "NO SOLUTION";
    else {
        if(MAX < 0)
            cout << MAX;
        else if(MIN >= 0)
            cout << MIN;
        else 
            cout << 0;
    }
    return 0;
}
