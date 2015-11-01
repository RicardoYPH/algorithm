#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
const int mod = 1e9 + 7;

ll a[N];

int main() {
	int n;

	while (~scanf("%d", &n)) {

		ll tot = 1;
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", a + i);
			tot = tot * a[i];	
			if (flag) tot %= (mod - 1);
			if (tot > (mod - 1)) {
				flag = 1;
				tot %= mod - 1;
			}
		}
		ll ans = 0;

		for (int i = 1; i <= n; i++) {
			tmp = qpow(i, n * (n + 1) / 2);
		}

	}


	return 0;
}
