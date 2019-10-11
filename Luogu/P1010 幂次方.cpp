#include <iostream>
#include <cstdio>

using namespace std;

int init[20], input;

void calc(int num) {
	bool flag = false;
	if (num == 2 || num == 0) {
		cout << num;
		return;
	} else if (num == 1) {
		cout << "2(0)";
		return;
	}
	
	while (num) {
		for (int i = 15; i >= 2; i--) {
			int t = 0;
			
			if (num >= init[i]) {
				t = i;
				num -= init[i];
			}
			
			
			if (t) {
				if (flag)
					cout << "+";
				cout << "2(";
				calc(t);
				cout << ")";
				flag = true;
			}
		}
		
		if (num == 2 || num == 3) {
			if (flag)
					cout << "+";
			num -= 2;
			cout << "2";
			flag = true;
		}
		
		if (num == 1) {
			if (flag)
					cout << "+";
			num--;
			cout << "2(0)";
		}
	}
}

int main() {
	init[0] = 1;
	for (int i = 1; i <= 15; i++)
		init[i] = init[i - 1] * 2;
	
	cin >> input;
	
	calc(input);
		
	return 0;
}
