#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

char b[N];

int getPhi(ll n) {
	ll res = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res = res / i * (i - 1);
			while (n % i == 0) n /= i;
		}	
	}
	if (n > 1)
		res = res / n * (n - 1);
	return res;
}
ll multi(ll a, ll b, ll mod) {
	ll ans = 0;
	a %= mod;
	while(b) {
		if (b & 1) {
			ans = (ans + a) % mod;	
//			b--;
		}	
		b >>= 1;
		a = (a + a) % mod;
	}
	return ans;
}

ll qpow(ll a, ll b, ll mod) {
	ll ret = 1;
	ll tmp = a % mod;
	while (b) {
		if (b & 1) {
			ret = multi(ret, tmp, mod);
		}
		tmp = multi(tmp, tmp, mod);
		b >>= 1;
	}
	return ret;
}

int main() {

	ll a, c;
	while (~scanf("%I64d%s%I64d", &a, b, &c)) {
		ll p = getPhi(c);
		int len = strlen(b);
		ll m = 0;
		if (len < 11) {
			for (int i = 0; i < len; i++) {
				m = m * 10 + b[i] - '0';	
			}
			if (m > p) 
				m = m % p + p;
		}
		else {
			for (int i = 0; i < len; i++) {
				m = (m * 10 + (b[i] - '0')) % p;
			}
			m = m + p;
		}
		ll ans = qpow(a, m, c);
		printf("%I64d\n", ans);
	}
	return 0;
}
