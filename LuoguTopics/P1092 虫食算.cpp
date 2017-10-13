#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int n;

char A[30], B[30], C[30];

int set[30];

bool used[30];

inline void reset(char * Array) {
	for (int i = 1; i <= n; i++)
		Array[i] -= 'A' - 1;
}

inline void init() {
	scanf("%s%s%s", A + 1, B + 1, C + 1);
	
	reset(A);
	reset(B);
	reset(C);
	
	memset(set, -1, sizeof(set));
}

bool judge(bool flag) {
	if (set[(int)A[1]] >= 0 && set[(int)B[1]] >= 0 && set[(int)A[1]] + set[(int)B[1]] >= n)
		return false;

	if (flag) {
		int num = 0;
		for (int i = n; i >= 1; i--) {
			if ((set[(int)A[i]] + set[(int)B[i]] + num) % n != set[(int)C[i]])
				return false;
			num = set[(int)A[i]] + set[(int)B[i]] + num >= n;
		}
		
		for (int i = 1; i <= n; i++)
			printf("%d ", set[i]);
			
		exit(0);
	} else {
		int num = 0;
		
		for (int i = n; i >= 1; i--) {
			if (set[(int)A[i]] >= 0 && set[(int)B[i]] >= 0 && set[(int)C[i]] >= 0 && num >= 0) {
				if ((set[(int)A[i]] + set[(int)B[i]] + num) % n != set[(int)C[i]])
					return false;
				num = (set[(int)A[i]] + set[(int)B[i]] + num) >= n;
			} else if (set[(int)A[i]] >= 0 && set[(int)B[i]] >= 0 && set[(int)C[i]] >= 0) {
				if ((set[(int)A[i]] + set[(int)B[i]]) % n != set[(int)C[i]] && (set[(int)A[i]] + set[(int)B[i]] + 1) % n != set[(int)C[i]])
					return false;
				num = -1;
			} else
				num = -1;
		}
	}
	
	return true;
}

char * getArray(int id) {
	if (id == 1)
		return A;
	else if (id == 2)
		return B;
	return C;
}

void search(int pos, int id) {
    if (!judge(pos == 1 && id == 3))
        return;
    
    if (set[(int)getArray(id)[pos]] < 0) {
        for (int i = n - 1; i >= 0; i--) {
            if (!used[i]) {
                used[i] = true;
                set[(int)getArray(id)[pos]] = i;
                
                if (id == 3)
                    search(pos - 1, 1);
                else
                    search(pos, id + 1);
                    
                used[i] = false;
                set[(int)getArray(id)[pos]] = -1;
            }
        }
    } else {
        if (id == 3)
            search(pos - 1, 1);
        else
            search(pos, id + 1);
    }
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &n);
	
	init();
	
	search(n, 1);
	
	return 0;
}
