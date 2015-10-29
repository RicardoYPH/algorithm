#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MOD = 1000;

typedef long long ll;
ll ls;
double ms;

double change(double a) {
	while (a > 1) {
		a = a / 10;	
	}
	while (a < 0.1) {
		a = a * 10;
	}
	return a;
}

void qpow(ll a, ll b) {
	ms = ls = 1;
	ll tmp1 = a;
	double tmp2 = change((double)a);

	while (b) {
		if (b & 1) {
			ls = (ls * tmp1) % MOD;	
			ms = change(ms * tmp2);
		}
		tmp1 = (tmp1 * tmp1) % MOD;
		tmp2 = change(tmp2 * tmp2);
		b >>= 1;	
	}

}


int main() {
	
	int t;

	scanf("%d", &t);

	int CASE = 1;

	while (t--) {
		ll n, k;
		scanf("%lld%lld", &n, &k);
		qpow(n, k);
		while (ms < 100) {
			ms *= 10;
		}
		printf("Case %d: %lld %.3lld\n", CASE++, (ll)ms, ls);
	}

	return 0;
}
