#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

char Map[N][N];
int mov[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};
int V[N][N][4][3];
int n, m;

bool check(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m && Map[x][y] != '0') 
		return true;
	return false;
}

int getLen(int x, int y, int dir, int turn) {
	if (V[x][y][dir][turn + 1] != -1) return V[x][y][dir][turn + 1];
	int ans = 0;
	
	int tx = x + mov[dir][0], ty = y + mov[dir][1];
	
	if (check(tx, ty)) {
		ans = V[x][y][dir][turn + 1] = getLen(tx, ty, (dir + turn + 4) % 4, turn * -1) + 1;
	}

	
		

	return ans;
	
}

int main() {

	int t;
	scanf("%d", &t);

	while(t--) {
		scanf("%d%d", &n, &m);
		int ans = 0;
		int flag = 0;

		for (int i = 1; i <= n; i++) {
			scanf("%s", Map[i] + 1);
		}
		memset(V, -1, sizeof(V));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (Map[i][j] == '1') {
					flag = 1;
					int tmp = 0;
					for (int k = 0; k < 4; k++) {
						tmp += getLen(i, j, k, 1);
					}
//					cout << i << " " << j << " "  << tmp << endl;
					ans = max(ans, tmp);
				}
			}
		}
		printf("%d\n", ans + flag);
	}

	
	return 0;
}
