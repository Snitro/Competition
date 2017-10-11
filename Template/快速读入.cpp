inline int read() {
	int k = 0;
	int f = 1;
	char c = getchar();
	
	while (c > '9' || c < '0') {
		if (c == '-')
			f = -1;
		c = getchar();
	}
	
	while (c <= '9' && c >= '0') {
		k = k * 10 + c - '0';
		c = getchar();
	}
	
	return f * k;
}
