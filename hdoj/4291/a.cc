#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2;
const int mod = 1e9 + 7;

ll fac[2][505];
int cnt, cnt;
ll pri[6] = {2, 3, 7, 109, 167, 500000003};//分解质因子
ll num[6] = {4, 2, 1, 2, 1, 1};

struct Matrix {
	ll m[N][N];
};

Matrix A;

int main() {
	fac[0][0] = 1;
	fac[0][1] = 2;
	fac[0][2] = 500000003;
	fac[0][3] = 1000000006;

	ll a, b, c, d;

	while (cin >> a >> b >> c >> d) {

		ll t = a * a + 4 * b;
		A.m[0][0] = a;
		A.m[0][1] = b;
		A.m[1][0] = 1;
		A.m[1][1] = 0;

		if (Legendre(t, mod) == 1) {
			for (int i = 0; i < 4; i++) {

				if (OK(A, fac[0][i])) {
					cout << fac[0][i] << endl;
					break;
				}
			}
		}
		else {
			ct = 0;
			cnt = 6;
		}
		

	}


	return 0;
}
