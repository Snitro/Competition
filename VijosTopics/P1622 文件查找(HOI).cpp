#include <iostream>
#include <cstdio>

using namespace std;

struct Stack {
	int top;
	string names[3000];
};

Stack stack;

string Find;

bool have(string s) {
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '.')
			return true;
	
	return false;
}

void new_file(int x) {
	string name;
	
	for (int i = 1; i <= x; i++) {
		cin >> name;
		
		if (name == Find) {
			for (int i = 1; i <= stack.top; i++)
				cout << stack.names[i] << "\\";
			cout << Find << endl;
		}
		if (!have(name)) {
			stack.names[++stack.top] = name;
			int a;
			scanf("%d", &a);
			new_file(a);
		}
	}
	stack.top--;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	cin >> Find;
	
	string s;
	
	while (cin >> s) {
		if (s == Find) {
			for (int i = 1; i <= stack.top; i++)
				cout << stack.names[i] << "\\";
			cout << Find << endl;
		}
		if (!have(s)) {
			stack.names[++stack.top] = s;
			int a;
			scanf("%d", &a);
			new_file(a);
		}
	}
	
	return 0;
}
