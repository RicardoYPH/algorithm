#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 5 * 1e4 + 10;

int v[N], h[N];
int c[N];

int main() {
	int t;
	scanf("%d", &t);
	
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		memset(v, 0, sizeof(v));
		memset(h, 0, sizeof(h));
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", c + i, v + i);
		}
		for (int i = 1; i <= m; i++) {
			int tmp;
			scanf("%d", &tmp);
			h[tmp]++;
		}
		int hurt[2] = {0};
		int ans = n;
		int flag = 0;
		for (int i = n; i >= 1; i--) {
			hurt[1] -= h[i];
			hurt[0] -= h[i];
			if (v[i] < hurt[1 - c[i]]) {
				ans--;
			}
			hurt[c[i]] = max(hurt[c[i]], v[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
