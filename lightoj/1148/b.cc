#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	int f[60];
	int CASE = 1;

	while (t--) {
		int n;
		scanf("%d", &n);
		memset(f, 0, sizeof(f));
		for (int i = 0; i < n; i++) {
			scanf("%d", f + i);
		}
		sort(f, f + n);f[n] = -1;

		int ans = 0;
		int tmp = f[0];
		int tcnt = 0;

		for (int i = 0; i <= n; i++) {
			if (tmp == f[i]){
				tcnt ++;
			}
			else {
				if (tcnt > tmp + 1) {
					ans += (tcnt / (tmp + 1) + (tcnt % (tmp + 1) != 0)) * (tmp + 1);
				}
				else {
					ans += tmp + 1;
				}
				
				tmp = f[i];
				tcnt = 1;
			}

		}

		printf("Case %d: %d\n", CASE++, ans);
	}

	return 0;
}
