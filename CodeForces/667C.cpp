#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

string temp;

int len;

bool f[10005], two[10005], three[10005];

map <string, bool> Map;

string ans[10005];

int main() {
	cin >> temp;
	
	for (unsigned int i = 2; i <= temp.size() - 5; i++) {
		if (i == 2 || i == 3) {
			f[i] = true;
			Map[temp.substr(temp.size() - i, i)] = true;
			ans[++len] = temp.substr(temp.size() - i, i);
			
			if (i == 2)
				two[i] = true;
			else 
				three[i] = true;
		} else {
			string Two = temp.substr(temp.size() - i, 2);
			string Three = temp.substr(temp.size() - i, 3);
			
			if (f[i - 2] && (three[i - 2] || (two[i - 2] && Two != temp.substr(temp.size() - i + 2, 2)))) {
				f[i] = true;
				two[i] = true;
				if (!Map[Two]) {
					Map[Two] = true;
					ans[++len] = Two;
				}
			}
			
			if (f[i - 3] && (two[i - 3] || (three[i - 3] && Three != temp.substr(temp.size() - i + 3, 3)))) {
				f[i] = true;
				three[i] = true;
				if (!Map[Three]) {
					Map[Three] = true;
					ans[++len] = Three;
				}
			}
		}
	}
	
	sort(ans + 1, ans + 1 + len);
	
	cout << len << endl;
	
	for (int i = 1; i <= len; i++) {
		cout << ans[i] << endl;
	}
	
	return 0;
}
