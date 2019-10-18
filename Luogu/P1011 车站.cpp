#include <iostream>
#include <cstdio>

using namespace std;

int a, n, m, x, u;

int all[50][2],
	in[50][2],
	out[50][2];

int main() {
	cin >>  a >> n >> m >> x;
	
	all[1][0] = a;
	in[1][0] = a;
	
	all[2][0] = a;
	in[2][1] = 1;
	out[2][1] = 1;
	
	for(int i = 3; i < n; i++) {
		in[i][0] = in[i - 1][0] + in[i - 2][0];
		in[i][1] = in[i - 1][1] + in[i - 2][1];
		
		out[i][0] = in[i - 1][0];
		out[i][1] = in[i - 1][1];
		
		all[i][0] = all[i - 1][0] + in[i][0] - out[i][0];
		all[i][1] = all[i - 1][1] + in[i][1] - out[i][1];
	}
	
	u = (m - all[n - 1][0]) / all[n - 1][1];
	
	cout << (all[x][0] + all[x][1] * u);
	
	return 0;
} 
