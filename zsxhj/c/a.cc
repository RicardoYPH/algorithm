#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef unsigned long long ll;

ll getPhi(ll m) {
	ll res = m;
	for (int i = 2; i * i <= m; i++) {
		if (m % i == 0) {
			res = res / i * (i - 1);
			while (m % i == 0) 
				m /= i;
		}
	}
	if (m > 1) {
		res = res / m * (m - 1);	
	}
	return res;
}

ll qpow(ll a, ll b, ll m) {
	ll res = 1;
	ll tmp = a % m;
	while (b) {
		if (b & 1) {
			res = (res * tmp) % m;	
		}

		tmp = (tmp * tmp) % m;
		b >>= 1;
	}
	return res;
}

int main() {

	int t;
	scanf("%d", &t);

	int CASE = 1;

	while (t--) {

		ll b, p, m;	
		scanf("%llu%llu%llu", &b, &p, &m);
		printf("Case #%d: ", CASE++);

		if (b == 0 && p == 1) {
			if(m == 18446744073709551615ull) 
				printf("18446744073709551616\n");
			else 
				printf("%llu\n", m + 1);
			continue;
		}

		ll ans = 0;

		if (b == 0) 
			ans++;
		ll phi = getPhi(p);	
		ll i;
		ll A = 1;
		for (i = 1; i <= m; i++) {
			A = (A * i) % phi;
			if (A == 0) 
				break;
			if (qpow(i, A + phi, p) == b) 
				ans++;
		}

		for (int k = 0; i <= m && k < p; k++, i++) {
		
			if (qpow(i, phi, p) == b) 
				ans += (m -i) / p + 1;
		}

		printf("%llu\n", ans);
	}

	return 0;
}
