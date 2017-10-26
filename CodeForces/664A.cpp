#include <iostream>
#include <cstring>

using namespace std;

string a, b;

int main() {
	freopen("in.txt", "r", stdin);
	
	cin >> a >> b;
	
	if (a == b)
		cout << a;
	else 
		cout << 1;
	
	return 0;
}
