#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

const int N = 2 * 1e6;

struct node {
	int loc, step;
};

int n, k;

map <int, bool> vis;

int check(node tmp) {
	return tmp.loc >= 0 && vis[tmp.loc] == 0 && tmp.loc <= 2 * k;
}

void getN(node & tmp, int loc, int step) {
	tmp.loc = loc;
	tmp.step = step;
}

int bfs(int t) {
	node tmp = {t, 0};
	queue<node> q;
	q.push(tmp);

	node now;

	while (q.empty() != 1) {
		tmp = q.front();
		if (tmp.loc == k) 
			return tmp.step;
		q.pop();
		getN(now, tmp.loc * 2, tmp.step + 1);
		if (check(now)) {
			vis[now.loc] = 1;
			if (now.loc == k) return now.step;
			q.push(now);
		}
		getN(now, tmp.loc + 1, tmp.step + 1);
		if (check(now)) {
			vis[now.loc] = 1;
			if (now.loc == k) return now.step;
			q.push(now);
		}
		getN(now, tmp.loc - 1, tmp.step + 1);
		if (check(now)) {
			vis[now.loc] = 1;
			if (now.loc == k) return now.step;
			q.push(now);
		}

	}
	return -1;
}

int main() {

	while (~scanf("%d%d", &n, &k)) {
		if (n > k) {
			printf("%d\n", n - k);
			continue;
		}
		int ans = 0;
		vis.clear();
		ans += bfs(n);
		printf("%d\n", ans);

	}


	return 0;
}
