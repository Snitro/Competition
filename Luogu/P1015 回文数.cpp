#include <iostream>
#include <cstdio> 
#include <cstdlib>

using namespace std;

int N, num[105], num1[105], len, ans;

void doit() {
	int up = 0, temp;
	
	for (int i = 1; i <= len; i++)
		num1[len + 1 - i] = num[i];
		
	for (int i = 1; i <= len; i++) {
		temp = num[i] + num1[i] + up;
		num[i] = temp % N;
		up = temp / N;
	}
	
	while (up != 0) {
		num[++len] += up % N;
		up /= N;
	}
	
	ans++;
}

bool judge() {
	if (ans == 30)
		return false;
	
	for (int i = 1; i <= len / 2; i++)
		if (num[len + 1 - i] != num[i]) 
			return false;
	
	return true;
}

int main() {
	int read;
	scanf("%d", &N);
	
	if (N != 16) {
		scanf("%d", &read);
		
		while (read != 0) {
			num[++len] = read % 10;
			read /= 10;
		}
	} else {
		scanf(" ");
		
		char temp;
		
		while ((temp = getchar()), (temp >= '0' && temp <= '9') || (temp >= 'A' && temp <= 'Z'))
			if (temp >= '0' && temp <= '9')
				num1[++len] = temp - '0';
			else
				num1[++len] = temp - 'A' + 10;
		
		for (int i = 1; i <= len; i++)
			num[len + 1 - i] = num1[i];
	}
	
	while (!judge())
		doit();
		
	if (ans <= 30)
		cout << "STEP=" << ans;
	else 
		cout << "Impossible!";
	
	return 0;
}
