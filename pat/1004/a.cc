#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

const int N = 110;

vector <int> V[N];
int num[N];
int maxl = 0;

void dfs(int t, int l) {
	if (l > maxl) {
		maxl = l;	
	}
	int size = V[t].size();
	for (int i = 0; i < size; i++) {
		if (V[V[t][i]].size() == 0) {
			num[l + 1]++;	
		}
		dfs(V[t][i], l + 1);	
	}
}

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	int k;
	int root, child;
	for (int i = 0; i < N; i++) {
		V[i].clear();	
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &root);	
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &child);
			V[root].push_back(child);	
		}
	}
	if (V[1].size() == 0) {
		num[0] = 1;	
	}
	dfs(1, 0);

	for (int i = 0; i < maxl; i++) {
		printf("%d ", num[i]);	
	}
	printf("%d\n", num[maxl]);

	return 0;
}
