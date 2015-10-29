#include <bits/stdc++.h>

using namespace std;

const int N = 40;

int l, r, c;
char Map[N][N][N];

int mov[6][3] = {1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1};

bool vis[N][N][N];

struct node {
	int x, y, z, step;
};

bool check(node tmp) {
	if (tmp.x >= 1 && tmp.x <= l && tmp.y <= r && tmp.y >= 1 && tmp.z >= 1 && tmp.z <= c && vis[tmp.x][tmp.y][tmp.z] == 0 && Map[tmp.x][tmp.y][tmp.z] != '#')
		return true;
	return false;
}

int bfs(int x, int y, int z) {
	node tmp = {x, y, z, 0};
	vis[x][y][z] = true;
	queue <node> q;
	q.push(tmp);
	while (q.empty() != 1) {
		tmp = q.front();
		q.pop();

		node next;

		for (int i = 0; i < 6; i++) {
			next.x = tmp.x + mov[i][0];
			next.y = tmp.y + mov[i][1];
			next.z = tmp.z + mov[i][2];
			next.step = tmp.step + 1;
			if (check(next)) {
				vis[next.x][next.y][next.z] = 1;
				if (Map[next.x][next.y][next.z] == 'E') {
					return next.step;	
				}
				q.push(next);
			}

		}
	}
	return -1;
}


int main() {

	while (~scanf("%d%d%d", &l, &r, &c) && l + r + c) {
		int sx, sy, sz;
		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				scanf("%s", Map[i][j] + 1);
				for (int k = 1; k <= c; k++) 
					if (Map[i][j][k] == 'S') {
						sx = i, sy = j, sz = k;
					}
			}
		}

		int ans = bfs(sx, sy, sz);

		if (ans != -1) {
			printf("Escaped in %d minute(s).\n", ans);
		}
		else {
			printf("Trapped!\n");
		}

	}

	return 0;
}
