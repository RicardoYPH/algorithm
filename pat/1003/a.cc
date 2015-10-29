#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 510;

vector <int> V[MAXN];
int p[MAXN];
int cost[MAXN][MAXN];
int N, M, s, e;
int vis[MAXN];
int num, ans, mp;

void dfs(int s, int step, int people) {
	if (s == e) {
		if (step < ans) {
			ans = step;
			mp = people;
			num = 1;
		}	
		else if (step == ans) {
			mp = max(people, mp);	
			num++;
		}
		return;
	}
	vis[s] = 1;

	int size = V[s].size();

	for (int i = 0; i < size; i++) {
		if (vis[V[s][i]] == 0)
		dfs(V[s][i], step + cost[s][V[s][i]], people + p[V[s][i]]);	
	}
	vis[s] = 0;
}

int main() {
	num = 0;
	mp = 0;
	ans = 0x3f3f3f3f;

	scanf("%d%d%d%d", &N, &M, &s, &e);

	for (int i = 0; i < N; i++) {
		scanf("%d", p + i);	
	}

	int a, b, c;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &c);	
		V[a].push_back(b);
		V[b].push_back(a);
		cost[a][b] = cost[b][a] = c;
	}

	memset(vis, 0, sizeof(vis));
	dfs(s, 0, p[s]);

	printf("%d %d\n", num, mp);



	return 0;
}
