#include <iostream>
#include <cstdio>

using namespace std;

int n, m;

int data[201];

int MAX[200][20];
int MIN[200][20];

int sum[200];

int main() {
	freopen("in.txt", "r", stdin);
	
	int Max = 0, Min = 999999999;
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> data[i];
		
	for (int i = 1; i <= n; i++)
		data[i + n] = data[i];
	for (int b = 1; b <= n; b++) {
		
		for (int i = 1; i <= n; i++)
			sum[i] = (sum[i - 1] + data[i + b - 1]) % 10;
		
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++) {
				MIN[i][j] = 999999999;
				MAX[i][j] = 0;
			}
		
		for (int i = 1; i <= n; i++)
			MAX[i][1] = MIN[i][1] = (sum[i] + 10) % 10;
		
		MAX[0][0] = MIN[0][0] = 1;
		
		for (int i = 2; i <= m; i++)
			for (int j = i; j <= n; j++)
				for (int k = i - 1; k <= j - 1; k++) {
					MAX[j][i] = max(MAX[j][i], MAX[k][i - 1] * (((sum[j] - sum[k]) % 10 + 10) % 10));
					MIN[j][i] = min(MIN[j][i], MIN[k][i - 1] * (((sum[j] - sum[k]) % 10 + 10) % 10));
				}
		
		Max = max(Max, MAX[n][m]);
		Min = min(Min, MIN[n][m]);
	}
	
	cout << Min << endl << Max << endl;
	
	return 0;
}
