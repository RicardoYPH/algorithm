#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;
const int N = 1e6 + 10;

ll b[N], g[N];
ll n, m, k;
bool cmp(ll a, ll b) {
	return a >= b;
}
int find(ll x) {
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = m;
		ll ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (b[i] * g[mid] >= x) {
				ans = mid;
				l = mid + 1;
			}
			else 
				r = mid - 1;
		}
		res += ans;
	}
	return res >= k;
}
int main() {
	while (~scanf("%lld%lld%lld", &n, &m, &k)) {
		for (int i = 1; i <= n; i++) 
			scanf("%lld", b + i);
		for (int i = 1; i <= m; i++) 
			scanf("%lld", g + i);
		sort(b + 1, b + n + 1, greater<int>());
		sort(g + 1, g + m + 1, greater<int>());
		ll l = b[n] * g[m];
		ll r = b[1] * g[1];
		ll ans = l;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (find(mid)) {//判断mid是不是
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
