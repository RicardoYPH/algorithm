#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
const int N = 60;

int Map[N][N][N];
int ans;
int a, b, c, T;
int vis[N][N][N];

int mov[6][3] = {-1, 0, 0, 
				1, 0, 0,
			   	0, 1, 0,
				0, -1, 0,
				0, 0, 1, 
				0, 0, -1};


struct node {
	int x, y, z, step;
};

int bfs(int x, int y, int z) {

	node now; now.x = x; now.y = y; now.z = z; now.step = 0;

	queue <node> q;

	q.push(now);


	while (!q.empty()) {
		now = q.front();
		q.pop();
		if (now.step > T) 
			return -1;
		node next;
		if (now.x == a && now.y == b && now.z == c) {
			return now.step;
		}

		for (int k = 0; k < 6; k++) {

			next.x = now.x + mov[k][0];
			next.y = now.y + mov[k][1];
			next.z = now.z + mov[k][2];
			next.step = now.step + 1;

			if (next.x > 0 && next.x <= a && next.y > 0 && next.y <= b && next.z > 0 && next.z <= c && vis[next.x][next.y][next.z] == 0 && Map[next.x][next.y][next.z] == 0) {

				vis[next.x][next.y][next.z] = 1;
				if (next.x == a && next.y == b && next.z == c) {
					return next.step;
				}
				q.push(next);
			}
		}
	}
	return -1;

}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {


		scanf("%d%d%d%d", &a, &b, &c, &T);
		ans = 0x3f3f3f3f;
		memset(vis, 0, sizeof(vis));


		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) 
				for (int k = 1; k <= c; k++) 
					scanf("%d", &Map[i][j][k]);
		}

		ans = bfs(1, 1, 1);

		printf("%d\n", ans);

	}
}
