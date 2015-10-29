#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

ll powMod(ll a, ll b, ll mod) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}


ll comb(ll a, ll b, ll p) {
	if (a < b) return 0;
	if (a == b)  return 1;
	if (b > a - b) b = a - b;

	ll ans = 1, ca = 1, cb = 1;

	for (ll i = 0; i < b; i++) {
		ca = (ca * (a - i)) % p;
		cb = (cb * (b - i)) % p;
	}

	ans = (ca * powMod(cb, p - 2, p)) % p;
	return ans;

}

ll lucas(ll n, ll m, ll p) {

	ll ans = 1;
	while (n && m && ans) {
		ans = (ans * comb(n % p, m % p, p)) % p;
		n /= p;
		m /= p;
	}

	return ans;

}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%lld\n", (lucas(2 * n, n, m) - lucas(2 * n, n - 1, m) + m) % m);

	}

	return 0;
}
