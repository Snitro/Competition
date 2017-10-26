#include <iostream>
#include <cstdio>

using namespace std;

double a,b,c;

int main() {
    freopen("in.txt", "r", stdin);
    cin >> a >> b >> c;
    double s = ((a * c - a * b) * (b + c)) / (2 * c * b - 3 * b * b + c * c);
    printf("%.6lf", (s / double(c) + (a - s) / double(b)));
    return 0;
}
