#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 3;

struct matrix {
	ll num[N][N];	
	matrix () {
		memset(num, 0, sizeof(num));
	}
};

matrix multi(matrix ta, matrix tb, int mod) {
	matrix tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				tmp.num[i][j] = (tmp.num[i][j] + (ta.num[i][k] * tb.num[k][j]) % mod) % mod;
			}
		}
	}
	return tmp;
}

matrix qpow(matrix ta, int b, int mod) {
	matrix res;
	for (int i = 0; i < N; i++) {
		res.num[i][i] = 1;
	}
	while (b) {
		if (b & 1) res = multi(res, ta, mod);
		ta = multi(ta, ta, mod);
		b >>= 1;
	}
	return res;
}

int main() {
	ll n, m;
	while (~scanf("%lld%lld", &n, &m)) {
		matrix tmp;
		tmp.num[0][0] = tmp.num[0][2] = tmp.num[2][2] = tmp.num[1][0] = 1;
		tmp.num[0][1] = 2;
		tmp = qpow(tmp, n - 1, m);
		matrix ans;
		ans.num[0][0] = 1; ans.num[1][0] = 0; ans.num[2][0] = 1;
		ans = multi(tmp, ans, m);
		printf("%lld\n", ans.num[0][0]);
	}
	return 0;
}
