#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int N = 1e5 + 10;

int a[N];
int b[N];
int vis[N];
map <int, int> M;

int getLen(int ta) {
	int tb = M[ta];
	int cnt = 0;

	while (vis[ta] == 0) {
		vis[ta] = 1;
		ta = tb;
		tb = M[ta];
		cnt++;	
	}

	if (cnt > 1) 
		cnt--;
	return cnt;


}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		memset(vis, 0, sizeof(vis));

		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);	
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", b + i);	
			M[a[i]] = b[i];
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (vis[a[i]] == 0) 
				ans += getLen(a[i]);
		}
		printf("%d\n", ans);
	
	}


	return 0;
}
