#include <bits/stdc++.h>
using namespace std;

struct node {
	int l, r;
};

const int N = 40;
bool vis[N];
node tree[N];
vector <int> V;

void bfs(int root) {
	queue<int> q;
	q.push(root);	
	V.push_back(root);
	while (q.empty() != 1) {
		root = q.front();
		q.pop();
		if (tree[root].l != -1) {
			q.push(tree[root].l);
			V.push_back(tree[root].l);
		}
		if (tree[root].r != -1) {
			q.push(tree[root].r);
			V.push_back(tree[root].r);	
		}
	}
}

void dfs(int root) {
	if (tree[root].l != -1) 
		dfs(tree[root].l);
	V.push_back(root);
	if (tree[root].r != -1)
		dfs(tree[root].r);
}

int main() {
	int n;
	scanf("%d", &n);

	char l[N], r[N];
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < n; i++) {
		tree[i].l = tree[i].r = -1;
	}

	for (int i = 0; i < n; i++) {
		scanf("%s%s", l, r);	
		int tmp = 0;
		if (l[0] != '-') {
			tmp = atoi(l);
			vis[tmp] = true;
			tree[i].r = tmp;
		}
		if (r[0] != '-') {
			tmp = atoi(r);
			vis[tmp] = true;
			tree[i].l = tmp;
		}
	}
	int root = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) root = i;
	}

	bfs(root);
	int e = V.size();
	printf("%d", V[0]);
	for (int i = 1; i < e; i++) {
		printf(" %d", V[i]);
	}
	puts("");

	V.clear();

	dfs(root);

	e = V.size();
	printf("%d", V[0]);
	for (int i = 1; i < e; i++) {
		printf(" %d", V[i]);
	}
	puts("");


	return 0;
}
