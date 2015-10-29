#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef unsigned long long ll;

ll getPhi(ll n) {
	ll res = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res = res - res / i;	
			while(n % i == 0) n /= i;
		}	
	}
	if (n > 1) 
		res = res - res / n;
	return res;
}

ll qpow(ll a, ll b, ll m) {
	ll tmp = a % m;

	ll res = 1;

	while (b) {
		if (b & 1) {
			res = (res * tmp) % m;	
		}	

		tmp = (tmp * tmp) % m;
		b >>= 1;
	}

	return res;

}


ll dfs(ll p, ll m) {

	if (m == 1) 
		return 0;
	ll phi = getPhi(m);
	ll y = dfs(p, phi);
	ll res = qpow(p, y + phi, m);
	if (res == 0) 
		res += m;
	return res;
}

int main() {
	int p, m;
	ll A[13];
	A[0] = 1;
	for (int i = 1; i < 13; i++) {
		A[i] = A[i - 1] * i;	
	}

	scanf("%d%d", &p, &m);
	printf("%llu\n", dfs(p, A[m]) % A[m]);

	while(~scanf("%d%d", &p, &m)) {
		ll ans = dfs(p, A[m]) % A[m];		
		printf("\n%llu\n", ans);
	}


	return 0;
}
