#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int const mod = 10416;

int n, tot;

struct HashMap {
	string text;
	HashMap * next;
	
	HashMap() {
		next = NULL;
	}
} map[10420];

string temp;

bool find() {
	long long Hash = 0;
	HashMap * to;
	
	for (unsigned int i = 0; i < temp.size(); i++)
		Hash = (Hash * 256 % mod + temp[i] - '0') % mod;
	
	to = &map[Hash];
	
	while (to != NULL) {
		if ((*to).text == temp)
			return true;
			
		if ((*to).next == NULL)
			break;
		
		to = (*to).next;
	}
	
	(*to).next = new HashMap();
	
	(*(*to).next).text = temp;
	
	return false;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		
		if (find())
			tot++;
	}
	
	printf("%d", n - tot);
	
	return 0;
}
