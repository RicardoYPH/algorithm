#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 10;

char Map[N][N];
int ans;
int n, k;
int vis[N]; 

void dfs(int c, int q) {
	if (q == k) {
		ans++;
		return;
	}
	if (c == n) 
		return ;
	dfs(c + 1, q);
	for (int i = 0; i < n; i++) {
		if (vis[i] == 0 && Map[c][i] != '.') {
			vis[i] = 1;
			dfs(c + 1, q + 1);
			vis[i] = 0;
		}
	}
}

int main() {

	while (~scanf("%d%d", &n, &k)) {
		ans = 0;
		memset(vis, 0, sizeof(vis));
		if (n == -1 && k == -1) 
			break;

		for (int i = 0; i < n; i++) {
			scanf("%s", Map[i]);
		}
		dfs(0, 0);
		printf("%d\n", ans);
	}

	
	return 0;
}
