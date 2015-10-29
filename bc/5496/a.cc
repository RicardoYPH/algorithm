#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
const int mod = 1e9 + 7;

int num[N];
ll p[N];
ll f[N];
map <int, int> M;

int main() {
	int t;
	scanf("%d", &t);

	p[0] = 1;

	for (int i = 1; i < N; i++) 
		p[i] = (p[i - 1] * 2) % mod;

	while (t--) {

		int n;
		ll sum = 0;

		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", num + i);	
			sum = (sum + num[i]) % mod;
		}

		ll ans = (sum * p[n - 1]) % mod;

		M.clear();
		memset(f, 0, sizeof(f));

		for (int i = 1; i <= n; i++) {
			if (!M[num[i]]) {
				M[num[i]] = i;
			}	
			else {
				ll tmp = M[num[i]];	
				f[i] = (f[tmp] + p[tmp - 1]) % mod;
				M[num[i]] = i;
			}
		}
	
		for (int i = 1; i <= n; i++) {
			ll tmp = (((f[i] * p[n - i]) % mod ) * num[i] ) % mod;
			ans = (ans - tmp + mod) % mod;
		}

		printf("%lld\n", ans);
	
	}

	return 0;
}
