#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;

char temp[1005];

int query, one, zero, last, _one, _zero;

int l = 1, r, m;

int main() {
	scanf("%d", &n);
	r = n;
	
	for (int i = 1; i <= n; i++)
		temp[i] = '0';
		
	printf("? %s\n", temp + 1);
	fflush(stdout);
	
	cin >> query;
	last = query;
	
	_one = one = query;
	_zero = zero = n - query;
	
	while (true) {
		m = (l + r) >> 1;
		
		for (int i = l; i <= m; i++)
			temp[i] = temp[i] == '1' ? '0' : '1';
		
		printf("? %s\n", temp + 1);
		fflush(stdout);
		cin >> query;
		
		if (temp[m] == '1') {
			zero = (m - l + 1) - (query - last);
			zero = zero / 2 + (query - last);
			
			one = (m - l + 1) - zero;
		} else {
			one = (m - l + 1) - (query - last);
			one = one / 2 + (query - last);
			
			zero = (m - l + 1) - one;
		}
		
		if (one != 0 && zero != 0) {
			r = m;
			_one = one;
			_zero = zero;
		} else {
			l = m + 1;
			
			one = _one - one;
			zero = _zero - zero;
			
			_one = one;
			_zero = zero;
			
			if (l == r) {
				if (one == 0)
					cout << "! " << l << " " << m;
				else
					cout << "! " << m << " " << l;
				
				fflush(stdout);
				
				return 0;
			}
			
			if (one == 0 || zero == 0) {
				if (one == 0)
					cout << "! " << l << " " << m;
				else
					cout << "! " << m << " " << l;
				
				fflush(stdout); 
				
				return 0;
			}
		}
		
		last = query;
		
		if (l == r - 1) {
			temp[l] = temp[l] == '1' ? '0' : '1';
			
			printf("? %s\n", temp + 1);
			fflush(stdout);
			cin >> query;
			
			if ((query - last == 1 && temp[l] == '0') || (temp[l] == '1' && last - query == 1))
				cout << "! " << r << " " << l;
			else
				cout << "! " << l << " " << r;
				
			fflush(stdout);
				
			return 0;
		}
	}
	
	return 0;
}
