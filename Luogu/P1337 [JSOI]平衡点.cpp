#include <iostream>
#include <cmath>
#include <cstdio>

#define abs(x) ((x) >= 0 ? (x) : (-(x)))

using namespace std;

int n;
double x, y;

bool XF = true, YF = true;

struct Position {
    int x;
    int y;
    int power;
} positions[1005];

void solve(double move) {
    double X, Y, temp;
    X = Y = 0;
	
    for (int i = 1; i <= n; i++) {
	    temp = sqrt((x - positions[i].x) * (x - positions[i].x) + (y - positions[i].y) * (y - positions[i].y));
	    if (temp == 0)
			continue;
	    X += positions[i].power / temp * (positions[i].x - x);
	    Y += positions[i].power / temp * (positions[i].y - y);
	}
	
    temp = sqrt(X * X + Y * Y);
	
    x += move / temp * X;
    y += move / temp * Y;
}

int main() {
    freopen("in.txt", "r", stdin);
	
    scanf("%d", &n);
	
    for (int i = 1; i <= n; i++)
	    scanf("%d%d%d", &positions[i].x, &positions[i].y, &positions[i].power);
	
    double move = 5000, tx, ty;
	
    while (true) {
	    tx = x;
	    ty = y;
        
        solve(move);
        
        if (abs(tx - x) < 0.00001 && abs(ty - y) < 0.00001)
            break;
        
        if ((XF != (x > tx)) || (YF != (y > ty))) {
            XF = !x > tx;
            YF = !y > ty;
            move = move * 0.9;
        }
    }
    
    printf("%.3f %.3f", x, y);
    
    return 0;
}
