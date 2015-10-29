#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;

const int N = 1010;

struct node {
	
	ll A, B, C;
	bool operator < (node b) const {
		return B * b.C > C * b.B;	
	}

};

node p[N];
ll dp[N * 3];

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, t;
		scanf("%d%d", &n, &t);
		for (int i = 0; i < n; i++) {
			scanf("%lld%lld%lld", &p[i].A, &p[i].B, &p[i].C);	
		}
		sort(p, p + n);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			for (ll j = t; j >= p[i].C; j--) {
				dp[j] = max(dp[j], dp[j - p[i].C] + p[i].A - p[i].B * j);
			}
		}
		ll ans = 0;
		for (int i = 0; i <= t; i++) {
			ans = max(ans, dp[i]);	
		}
		printf("%lld\n", ans);
	}
	return 0;
}
