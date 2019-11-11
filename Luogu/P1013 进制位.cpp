#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int n;

string str[10][10];  // ÐÐ ÁÐ
string name[10]; 
string one;

int ans[10];

void setAns(string na, int a) {
	for (int i = 1; i < n; i++)
		if (name[i] == na) {
			if (ans[i] != -1 && ans[i] != a) {
				cout << "ERROR!";
				
				exit(0);
			} else if (ans[i] == -1)
				ans[i] = a;
		}
}

int getAns(string na) {
	for (int i = 1; i < n; i++)
		if (name[i] == na)
			return ans[i];
}

int getPos(string na) {
	for (int i = 1; i < n; i++)
		if (name[i] == na)
			return i;
			
	return -1;
}

void findAns(string an) {
	int a = getPos(one);
	int b = getPos(an);
	
	if (str[a][b] != str[b][a] || a * b < 0) {
		cout << "ERROR!";
				
		exit(0);
	}
	
	if (str[a][b].length() == 1) {
		setAns(str[a][b], 1 + getAns(an));
		
		findAns(str[a][b]);
	} else
		setAns(str[a][b].substr(1, 1), 0);
}

void judge() {
	for (int i = 1; i < n; i ++)
		for (int j = 1; j < n; j++)
			if (str[i][j].length() == 2 && getAns(str[i][j].substr(1, 1)) != (ans[i] + ans[j]) % (n - 1)) {
				cout << "ERROR!";
				
				exit(0);
			}
}

int main() {
	freopen("testdata.in", "r", stdin);
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
		ans[i] = -1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> str[i][j];
			
			if (str[i][j].length() == 2) {
				setAns(str[i][j].substr(0, 1), 1);
				one = str[i][j].substr(0, 1);
			}
		}
		
		if (i == 0)
			for (int j = 1; j < n; j++)
				name[j] = str[0][j];
	}
	
	findAns(one);
	
	judge();
	
	for (int i = 1; i < n; i++)
		cout << name[i] << "=" << getAns(name[i]) << " ";
		
	cout << endl << n - 1;
		
	return 0;
}
