#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 1e5 + 10;

char ch[N * 2];
char str[N * 2];
char r[N * 2];

int Min(int a, int b) {
	return a < b ? a : b;
}

int Max(int a, int b) {
	return a > b ? a : b;
}

void manacher(int n) {
	int mx = 0, id = 0, i;
	r[0] = 0;
	for (i = 1; i < n ;i++) {
		if (mx > i) {
			r[i] = Min(mx - i, r[2 * id - i]);	
		}	
		else 
			r[i] = 1;

		while (str[i - r[i]] == str[i + r[i]]) 
			r[i]++;
		if(r[i] + i > mx) {
			mx = r[i] + i;
			id = i;
		}
	
	}
}

int pre() {
	int i, j = 0;
	str[j++] = '$';
	for (i = 0; ch[i]; i++) {
		str[j++] = '#';
		str[j++] = ch[i];
	}
	str[j++] = '#';
	str[j] = 0;
	return j;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(r, 0, sizeof(r));
		memset(str, 0, sizeof(str));
		memset(ch, 0, sizeof(ch));
		scanf("%s", ch);
		int ans = 0; 
		int len = pre();
		manacher(len);
		for (int i = 0; i < len; i++) {
			ans = Max(ans, r[i]);	
		}
		printf("%d\n", ans - 1);
	}

	return 0;
}
