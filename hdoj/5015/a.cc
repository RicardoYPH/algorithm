#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 15;
const int mod = 1e7 + 7;

struct matrix {
	ll num[N][N];
	matrix() {
		memset(num, 0, sizeof(num));
	}
};
int n, m;

matrix multi(matrix a, matrix b) {
	matrix tmp;
	for (int i = 1; i <= n + 2; i++) {
		for (int j = 1; j <= n + 2; j++) {
			for (int k = 1; k <= n + 2; k++) {
				tmp.num[i][j] = (tmp.num[i][j] + a.num[i][k] * b.num[k][j]) % mod;
			}
		}
	}	
	return tmp;
}

matrix qpow(matrix a, int b) {
	matrix tmp;
	for (int i = 1; i <= n + 2; i++) tmp.num[i][i] = 1;
	while (b) {
		if (b & 1) tmp = multi(tmp, a);
		a = multi(a, a);
		b >>= 1;
	}
	return tmp;
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		matrix a, b;
		a.num[1][1] = 23;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a.num[i + 1][1]);
		}
		a.num[n + 2][1] = 3;
		for (int i = 1; i <= n + 1; i++) 
			b.num[i][1] = 10;
		for (int i = 1; i <= n + 2; i++) 
			b.num[i][n + 2] = 1;
		for (int i = 2; i <= n + 1; i++) {
			for (int j = 2; j <= i; j++) 
				b.num[i][j] = 1;
		}
		b = qpow(b, m);
		a = multi(b, a);
		cout << a.num[n + 1][1] << endl;
	}
	return 0;
}
