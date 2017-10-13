#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t, n;

char Men_map[30], Women_map[30], temp[10];

int Men_id[30], Women_id[30];

int Women_pos[30][30], Men_pos[30][30];

int Men_choice[30][2], Women_choice[30];

void init() {
	memset(Men_map, 0, sizeof(Men_map));
	memset(Women_map, 0, sizeof(Women_map));
	memset(Men_id, 0, sizeof(Men_id));
	memset(Women_id, 0, sizeof(Women_id));
	memset(Women_pos, 0, sizeof(Women_pos));
	memset(Men_pos, 0, sizeof(Men_pos));
	memset(Men_choice, 0, sizeof(Men_choice));
	memset(Women_choice, 0, sizeof(Women_choice));
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d", &t);
	
	while (t--) {
		init();
		
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			scanf("%s", temp);
			Men_map[i] = temp[0];
			Men_id[temp[0] - 'a' + 1] = i;
		}
		
		for (int i = 1; i <= n; i++) {
			scanf("%s", temp);
			Women_map[i] = temp[0];
			Women_id[temp[0] - 'A' + 1] = i;
		}
		
		for (int i = 1; i <= n; i++) {
			scanf("%s", temp);
			
			for (unsigned int j = 2; j < strlen(temp); j++)
				Men_pos[i][j - 1] = temp[j] - 'A' + 1;
		}
		
		for (int i = 1; i <= n; i++) {
			scanf("%s", temp);
			
			for (unsigned int j = 2; j < strlen(temp); j++)
				Women_pos[i][Men_id[temp[j] - 'a' + 1]] = j - 1;
		}
		
		int to, have;
		bool flag;
		
		while (true) {
			for (int i = 1; i <= n; i++) {
				if (Men_choice[i][0] == 0) {
					to = Men_pos[i][++Men_choice[i][1]];
					
					if (Women_choice[to]) {
						have = Women_choice[to];
						if (Women_pos[to][i] < Women_pos[to][have]) {
							Women_choice[to] = i;
							Men_choice[have][0] = 0;
							Men_choice[i][0] = to;
						}
					} else {
						Men_choice[i][0] = to;
						Women_choice[to] = i;
					}
				}
			}
			
			flag = true;
			
			for (int i = 1; i <= n; i++)
				if (Men_choice[i][0] == 0) {
					flag = false;
					break;
				}
				
			if (flag)
				break;
		}
		
		for (int i = 1; i <= n; i++)
			printf("%c %c\n", Men_map[i], Women_map[Men_choice[i][0]]);
		printf("\n");
	}
	
	return 0;
}
