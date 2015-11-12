#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2;
const int mod = 1e9 + 7;

struct matrix {
	ll num[N][N];
	public:
	void init() {
		memset(num, 0, sizeof(num));
	}
};

ll qmod(ll a) {
	while (a < 0) {
		a += mod;
	}
	return a % mod;
}

matrix multi(matrix ta, matrix tb) {
	matrix tmp;
	tmp.init();
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 2; i++) {
			if (ta.num[i][k]) {
				for (int j = 0; j < 2; j++) {
					tmp.num[i][j] += qmod(ta.num[i][k] * tb.num[k][j]);
					tmp.num[i][j] = qmod(tmp.num[i][j]);
				}
			}
		}
	}	
	return tmp;
}

matrix qpow (matrix a, ll b) {
	matrix tmp;
	tmp.init();
	tmp.num[0][0] = tmp.num[1][1] = 1;
	while (b) {
		if (b & 1) tmp = multi(tmp, a);
		a = multi(a, a);
		b >>= 1;
	}
	return tmp;
}

int main() {

	ll x, y, n;

	cin >> x >> y >> n;

	matrix tmp;
	tmp.num[0][0] = 1;
	tmp.num[0][1] = mod - 1;
	tmp.num[1][0] = 1;
	tmp.num[1][1] = 0;
	tmp = qpow(tmp, n - 1);	
	ll ans = qmod(qmod(tmp.num[1][0] * y) + qmod(tmp.num[1][1] * x));
	printf("%lld\n", ans);
	return 0;
}
