#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 20;

int Map[N][N];
int hit[N][N], ahit[N][N];
const int INF = 0x3f3f3f3f;
int ans, r, c;
int m, n;
int mov[5][2] = {1, 0, -1, 0, 0, 1, 0, -1};

bool get(int x, int y) {
	int res = Map[x][y];
	res += ahit[x][y];
	for (int i = 0; i < 4; i++) {
		int tx = x + mov[i][0];
		int ty = y + mov[i][1];
		if (tx >= 0 && tx < m && ty >= 0 && ty < n) 
			res += ahit[tx][ty];
	}
	return res & 1;
}

int solve() {

	int res = 0;

	for (int i = 1; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (get(i - 1, j)) 
				ahit[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (get(m - 1, i)) 
			return INF;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			res += ahit[i][j];
		}
	}
	return res;
}

int main() {

	while (~scanf("%d%d", &m, &n)) {
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) 
				scanf("%d", &Map[i][j]);
		}

		int e = 1 << n;
		int ans = INF;
		memset(hit, 0, sizeof(hit));

		for (int i = 0; i < e; i++) {
			memset(ahit, 0, sizeof(ahit));
			for (int j = 0; j < n; j++) 
				if (i & (1 << j)) ahit[0][j] = 1;
			int tmp = solve();
			if (tmp < ans) {
				ans = tmp;
				memcpy(hit, ahit, sizeof(ahit));
			}
		}
		if (ans == INF) {
			printf("IMPOSSIBLE\n");
		}
		else {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) 
					printf("%d%c", hit[i][j], j == n - 1 ? '\n' : ' ');
			}
		}

	}
	return 0;
}
