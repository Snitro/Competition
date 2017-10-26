#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;

double Log(long long n){
	if (n == 0)
		return 0;
	return log(n) / log(10);
}

void func() {
	long long left = max(sqrt(n - 1), 1.0),right = max(n - 1, 1);
	while (left != right) {
		long long mid = (right + left) / 2;
		double v = mid * Log(mid);
		if (v == n - 1) {
			cout << v;
			return;
		} else if (v < n - 1)
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (left * Log(left) < n - 1)
		cout << left + 1;
	else
		cout << left;
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	func();
	return 0;
}
