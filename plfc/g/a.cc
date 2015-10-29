#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long ll;
const int MOD = 76543;
int hs[MOD], head[MOD], next[MOD], id[MOD], top;

void insert(int x, int y) {
	int k = x % MOD;
	hs[top] = x, id[top] = y, next[top] = head[k], head[k] = top++;
}

int find(int x) {
	int k = x % MOD;
	for (int i = head[k]; i != -1; i = next[i]) 
		if (hs[i] == x) 
			return id[i];
	return -1;
}

int BSGS(int a, int b, int n) {
	memset(head, -1, sizeof(head));
	top = 1;
	if (b == 1) 
		return 0;
	int m = sqrt(n * 1.0), j;	
	ll x = 1, p = 1;
	for (int i = 0; i < m; ++i, p = p * a % n)
		insert(p * b % n, i);
	for (ll i = m; ;i += m) {
		if ( (j = find(x = x * p  % n)) != -1) 
			return i - j;
		if (i > n)
			break;
	}
	return -1;
}

int main() {
	int x, z, k;
	while (~scanf("%d%d%d", &x, &z, &k)) {
		if (x == 0 && z == 0 && k == 0) 
			break;
		int ans = BSGS(z, k, x);
		if (ans == -1) 
			puts("no solution");
		else  
			printf("%d\n", ans);
	}
	return 0;
}
