#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll p, m;

ll gcd (ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

ll f(ll a, ll b) {

	if (a < 0 || b < 0) 
		return 0;

	ll ma = a % p, mb = b % p;
	ll ans = (a / p) * (b / p) * p;

	ans += (ma + 1) * (b / p) + (mb + 1) * (a / p);

	if (ma > m) {
		ans += min(m, mb) + 1;
		ll t = (p + m - ma) % p;
		if (t <= mb) ans += mb - t + 1;
	}
	else {
		ll t = (p + m - ma) % p;
		if (t <= mb) ans += min(m - t + 1, mb - t + 1);
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	int CASE = 1;
	while (t--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d >> p >> m;
		ll ans = f(b, d) - f(b, c - 1) - f(a - 1, d) + f(a - 1, c - 1);
		ll total = (b - a + 1) * (d - c + 1);
		ll td = gcd(ans, total);
		printf("Case #%d: %lld/%lld\n", CASE++, ans / td, total / td);
	}


	return 0;
}
