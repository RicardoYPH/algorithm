#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
	int t;
	scanf("%d", &t);
	int CASE = 1;
	while (t--) {
		ll n;	
		scanf("%lld", &n);
		ll s, e = (ll)sqrt(n);
		ll ans = 0;
		for (s = 1; s <= e; s++) {
			ans += n / s;	
			ans += (n / s - n / (s + 1)) * s;
		}
		if (n / (e + 1) < e)
			ans -= e;
	

		printf("Case %d: %lld\n", CASE++, ans);
	
	}

	return 0;
}
