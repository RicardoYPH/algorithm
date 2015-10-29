#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
int n;

int vis[210];
struct node {
	int a[110];
	int cnt;
	int r;
};

int getR(node tmp) {
	return (tmp.r * 10 + tmp.a[tmp.cnt - 1]) % n;
}

void getNew(node tmp, node & now, int n) {
	memcpy(now.a, tmp.a, sizeof(tmp.a));
	now.r = tmp.r;
	now.a[tmp.cnt] = n;
	now.cnt = tmp.cnt + 1;
	now.r = getR(now);
}

void bfs() {
	node tmp = {{1}, 1, 1 % n}	;
	queue <node> q;
	q.push(tmp);

	while (q.empty() != 1) {
		tmp = q.front();
		q.pop();
		node now;

		for (int i = 0; i <= 1; i++) {
			getNew(tmp, now, i);
			if (now.r == 0) {
				for (int j = 0; j < now.cnt; j++) {
					printf("%d", now.a[j]);
				}
				puts("");
				return ;
			}
			if (vis[now.r] == 0) {
				q.push(now);
				vis[now.r] = 1;
			}
			
		}
	}
}

int main() {
	while (~scanf("%d", &n) && n) {
		memset(vis, 0, sizeof(vis));
		if (n == 1) 
			printf("1\n");
		else 
			bfs();	

	}

	return 0;
}
