#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int fa[N];
int ce[N];
int tot[N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	memset(fa, 0, sizeof(fa));

	int fid;
	int k;
	int tmp;

	for (int i = 1; i <= m; i++) {
		scanf("%d", &fid);
		scanf("%d", &k);	
		for (int j = 1; j <= k; j++) {
			scanf("%d", &tmp);
			fa[tmp] = fid;
		}
	}
	
	for (int i = 1; i <= n; i++) 
		if (fa[i] == 0) ce[i] = 1;
	for (int i = 1; i < n; i++) {	
		for (int j = 1; j <= n; j++) {
			if (ce[fa[j]] == i) {
				ce[j] = i + 1;
				tot[i + 1]++;
			}
		}
	}

	int ans = 1, id = 1;
	for (int i = 2; i < n; i++) {
		if (ans < tot[i]) {
			ans = tot[i];
			id = i;
		}	
	}

	printf("%d %d\n", ans, id);


	return 0;
}
