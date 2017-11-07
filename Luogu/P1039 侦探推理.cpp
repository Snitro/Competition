#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, p, m, lie[20], ans;

char temp[10000];

string player[20];

string week[] = {"", "Monday.", "Tuesday.", "Wednesday.", "Thursday.", "Friday.", "Saturday.", "Sunday."};

struct Node {
	int id;
	int flag;
	int player;
	string name;
	string sentence;
} nodes[105];

bool endWith(string n, string m){
    if(n.size() < m.size())
        return false;
    else{
        for(int i = 1; i <= (int)m.size(); i++)
            if(n[n.size() - i] != m[m.size() - i])
                return false;
        return true;
    }
}

bool startWith(string n,string m){
    if(n.size() < m.size())
        return false;
    else{
        for(int i = 0; i < (int)m.size();i++)
            if(n[i] != m[i])
                return false;
        return true;
    }
}

void checker(int i) {
	string sentence = nodes[i].sentence;
	sentence = sentence.substr(1);
	
	for (int j = 1; j <= n; j++)
		if (nodes[i].name == player[j]) {
			nodes[i].id = j;
			break;
		}
	
	if (sentence == "I am guilty." || sentence == "I am not guilty.")
		nodes[i].flag = sentence == "I am guilty." ? 1 : 2;
	else if (endWith(sentence, "is guilty.") || endWith(sentence, "is not guilty.")) {
		stringstream st;
		st << sentence;
		string name;
		st >> name;
		
		nodes[i].flag = endWith(sentence, "is guilty.") ? 3 : 4;
		
		for (int k = 1; k <= n; k++)
			if (name == player[k]) {
				nodes[i].player = k;
				return;
			}
		
		nodes[i].player = 0;
	} else if (startWith(sentence, "Today is")) {
		string w = sentence.substr(9);
		nodes[i].flag = 5;
		
		for (int k = 1; k <= 7; k++)
			if (w == week[k]) {
				nodes[i].player = k;
				return;
			}
	}
}

void runner() {
	for (int i = 1; i <= n; i++) {
		for (int w = 1; w <= 7; w++) {
			bool _flag = true;
			memset(lie, 0, sizeof(lie));
			for (int j = 1; j <= m; j++) {
				int t = 0;
				if (nodes[j].flag == 1) {
					if (player[i] == nodes[j].name)
						t = 1;
					else
						t = 2;
				} else if (nodes[j].flag == 2) {
					if (player[i] == nodes[j].name)
						t = 2;
					else
						t = 1;
				} else if (nodes[j].flag == 3) {
					if (nodes[j].player == 0)
						t = 0;
					else if (nodes[j].player == i)
						t = 1;
					else
						t = 2;
				} else if (nodes[j].flag == 4) {
					if (nodes[j].player == 0)
						t = 0;
					else if (nodes[j].player == i)
						t = 2;
					else
						t = 1;
				} else if (nodes[j].flag == 5)
					t = w == nodes[j].player ? 1 : 2;
				
				if (t == 0)
					continue;
				
				if (!lie[nodes[j].id]) {
					lie[nodes[j].id] = t;
				} else if (lie[nodes[j].id] != t) {
					_flag = false;
					break;
				}
			}
			
			int MIN = 0, MAX = 0;
			
			for (int i = 1; i <= n; i++)
				if (lie[i] == 2) {
					MIN++;
					MAX++;
				} else if (lie[i] == 0)
					MAX++;
			
			if (MIN <= p && p <= MAX && _flag) {
				if (ans == 0)
					ans = i;
				else if (ans != i) {
					puts("Cannot Determine");
					exit(0);
				}
			}
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &p, &m);
	
	for (int i = 1; i <= n; i++)
		cin >> player[i];
		
	for (int i = 1; i <= m; i++) {
		cin >> nodes[i].name;
		nodes[i].name = nodes[i].name.substr(0, nodes[i].name.length() - 1);
		
		scanf("%[^\r\n]", temp);
		nodes[i].sentence = temp;
	}
	
	for (int i = 1; i <= m; i++)
		checker(i);
	
	runner();
	
	if (ans)
		puts(player[ans].data());
	else
		puts("Impossible");
	
	return 0;
}
