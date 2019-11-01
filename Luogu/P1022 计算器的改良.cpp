#include <iostream> 
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

char Read, Output;
int flag1 = 1, flag2 = 1;
int num, temp, sum, unknow;

void calc() {
	if (Read >= '0' && Read <= '9') {
		temp = Read - '0';
		num = num * 10 + temp;
	} else {
		if (Read < 'A' || Read > 'z') {
			sum += num * flag1 * flag2;
			num = 0;
		}
		
		if (Read == '=') {
			flag1 = -1;
			flag2 = 1;
		} else if (Read == '-')
			flag2 = -1;
		else if (Read == '+')
			flag2 = 1;
		else if (Read >= 'A' && Read <= 'z'){
			Output = Read;
			
			if (num == 0)
				num = 1;
			
			unknow += num * flag1 * flag2;
			num = 0;
		}
	}
}

int main() {
	while ((Read = getchar()) != EOF) 
		calc();
	
	calc();
	
	float ans = (0.0 - sum) / unknow;
	
	printf("%c=%.3f", Output, ans == 0 ? abs(ans) : ans);
	
	return 0;
}

