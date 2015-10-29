#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;

struct node {
	ll data;
	int loc;
	bool operator < (node b) const {
		return data < b.data;	
	}
};

node num[N * 2];
ll p[N];

int main() {
	p[0] = 1;
	for (int i = 1; i < N; i++) {
		p[i] = (p[i - 1] * 2) % mod;	
	}

	for (int i = 1; i < N; i++) {
		p[i] = (p[i] + p[i - 1]) % mod;	
	}
	int t;
	scanf("%d", &t);


	while (t--) {
		int n;
		scanf("%d", &n);
		int l, r;
		int cnt = 0;
		for (int i = 0; i < n; i ++) {
			scanf("%d%d", &l, &r);	
			if (l == r) 
				continue;

			num[cnt].data = l;
			num[cnt++].loc = 1;

			num[cnt].data = r;
			num[cnt++].loc = -1;
		}

		sort (num, num + cnt);

		ll ans = 0;
		int tmp;
		tmp = num[0].loc;
		ll start = num[0].data;

		for (int i = 1; i < cnt; i++) {
/*			for (int j = 1; j <= tmp; j++) {
				ans += ((num[i].data - start) * (p[n - j] + mod) % mod + mod) % mod;
				ans %= mod;
			}*/
			ans += ((num[i].data - start) * ((p[n - 1] - p[n - tmp - 1] + mod) % mod)) %mod;
			ans %= mod;
			start = num[i].data;
			tmp += num[i].loc;	
		}

		printf("%lld\n", ans);

		
	
	}


	return 0;
}
