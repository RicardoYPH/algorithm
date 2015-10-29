#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 5 * 1e3 + 10;

typedef long long ll;

ll mod[N];
ll m, r;

ll fun(ll cnt, ll len) {
	ll ans = 0;
	if (cnt == m) {
		ans +=  mod[m] * (mod[m] - 1) / 2 * (len / mod[m]);
 		ans += (len % mod[m]) * (len % mod[m] + 1) / 2;
	}
	else {
		if (len / mod[cnt] > 0) 
			ans += fun(cnt + 1, mod[cnt] - 1) * len / mod[cnt];
		if (len % mod[cnt] > 0) 
			ans += fun(cnt + 1, len % mod[cnt]);
	}
	return ans;

}

int main() {

	while(~scanf("%lld%lld", &m, &r)) {

		for (int i = 1; i <= m; i++) 
			scanf("%lld", mod + i);

		printf("%lld\n", fun(1, r));

	}


	return 0;
}
