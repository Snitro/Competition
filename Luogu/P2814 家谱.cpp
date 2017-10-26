#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int f[50005];

string getName[50005];

map <string, int > Map;

int n;

int getFrom(int a) {
	if (a == f[a])
		return a;
	return f[a] = getFrom(f[a]);
}

void Union(int a, int b) { // 把 a 合并到 b 下面 
	f[getFrom(a)] = getFrom(b);
}

bool check(int a, int b) {
	return getFrom(a) == getFrom(b);
}

int main() {
	freopen("in.txt", "r", stdin);

	for (int i = 1; i <= 50000; i++)
		f[i] = i;

	string father, data;

	while (cin >> data) {
		if (data[0] == '$')
			return 0;
			
		if (data[0] == '#') {
			data = data.erase(0, 1);
			father = data;
			
			if (!Map[father]) {
				Map[father] = ++n;
				getName[n] = father;
			}
			
		} else if (data[0] == '+'){
			data = data.erase(0, 1);
			
			if (!Map[data]) {
				Map[data] = ++n;
				getName[n] = data;
			}
			
			Union(Map[data], Map[father]);
		} else {
			data = data.erase(0, 1);
			cout << data << " " << getName[getFrom(Map[data])] << endl;
		}
		
	}
	
	return 0;
}
