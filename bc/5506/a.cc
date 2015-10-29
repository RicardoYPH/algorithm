#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> a[40];
int vis[10];
int cnt = 0;
int n, l;

void dfs(int x) {
	if (cnt > l) return;
	if (x > n) return;

	int e = a[x].size();

	for (int i = 0; i < n; i++) {
		vis[cnt++] = a[x][i];

	}
}

int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &l);
		for (int i = 1; i <= n; i++) {
			int m;
			scanf("%d", &m);
			for (int j = 1; j <= m; j++) {
				int tmp;
				scanf("%d", &tmp);
				a[i].push_back(tmp);
			}
		}

	}


	return 0;
}
