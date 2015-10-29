#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

ll multi(ll a, ll b, ll m) {
	ll ans = 0;
	a = a % m;

	while (b) {
		if (b & 1) {
			ans = (ans + a) % m;
			b--;
		}	
		b >>= 1;
		a = (a + a) % m;
	}
	return ans;
}

ll qpow(ll a, ll b, ll m) {
	ll tmp = a % m;
	ll ret = 1;
	while(b) {
		if (b & 1) {
			ret  = multi(ret, tmp, m);
		}	
		tmp = multi(tmp, tmp, m);
		b >>= 1;
	}
	return ret;
}

ll getPhi(ll n) {
	ll ret = n;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ret = ret / i * (i - 1);
			while (n % i == 0) 
				n /= i;
		}
	}

	if (n > 1) {
		ret = ret / n * (n - 1);	
	}

	return ret;

}

ll check(ll a, ll b, ll p) {
	
	ll ans = 1;
	for (int i = 0; i < b; i++) {
		ans = ans * a;	
		if (ans >= p) 
			return ans;
	}
	return ans;

}

ll getAns(ll n, ll m) {
	
	if (n < 10) {
		return n;	
	}
	ll p = getPhi(m);
	ll tmp = getAns(n / 10, p);
	ll che = check(n % 10, tmp, m);
	ll ans;
	if (che >= m) {
		ans = qpow(n % 10, tmp + p, m);
		if (ans == 0) 
			ans += m;
	}
	else 
		ans = che;

	return ans;

}

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		ll n, m;
		scanf("%lld%lld", &n, &m);
		ll ans = getAns(n, m);
		printf("%lld\n", ans);
	}

	return 0;
}
