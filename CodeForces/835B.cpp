#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int k;

long long sum;

string n;

priority_queue <int, vector<int>, greater<int> > que;

int main() {
	#ifdef debug
		freopen("in.txt", "r", stdin);
	#endif
	
	cin >> k >> n;
	
	for (unsigned int i = 0; i < n.size(); i++) {
		que.push(n[i] - '0');
		sum += n[i] - '0';
	}
	
	int tot = 0;
	int temp;
	
	while (sum < k) {
		temp = que.top();
		que.pop();
		
		sum += 9 - temp;
		tot++;
	}
	
	cout << tot << endl;
	
	return 0;
}

