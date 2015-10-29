#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5 + 10;

char ch[30];
char str[N];

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	memset(ch, 0, sizeof(ch));
	scanf("%s", str);
	for (int i = 0; i <= 26; i++) 
		ch[i] = 'a' + i;

	char tmp1[2], tmp2[2];
	for (int i = 1; i <= m; i++) {
		scanf("%s", tmp1);
		scanf("%s", tmp2);
		for (int i = 0; i <= 26; i++) {
			if (ch[i] == tmp1[0]) 
				ch[i] = tmp2[0];
			else if (ch[i] == tmp2[0]) 
				ch[i] = tmp1[0];
		}
	}
	for (int i = 0; i < n; i++) {
		str[i] = ch[str[i] - 'a'];
	}
	printf("%s\n", str);

	return 0;
}
