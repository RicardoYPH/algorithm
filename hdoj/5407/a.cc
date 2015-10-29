#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

const ll N = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll num[N];
bool is[N];
ll prime[N / 10];
int cnt;

ll inv(ll a, ll m) {
	ll p = 1, q = 0, b = m, c, d;
	while (b > 0) {
		c = a / b;	
		d = a; a = b; b = d % b;
		d = p; p = q; q = d - c * q;
	}
	return p < 0 ? p + m : p;
}

ll get_Prime() {
	cnt = 0;
	memset(is, 1, sizeof(is));
	int i, j;
	int s, e = sqrt(N);
	prime[cnt++] = 2;
	is[0] = is[1] = 0;

	for (i = 4; i < N; i += 2)
		is[i] = 0;

	for (i = 3; i <= e; i += 2)  
		if (is[i]) {
			prime[cnt++] = i;
			for (s = i * 2, j = i * i; j < N; j += s) 
				is[j] = 0;
				
		}
	for (; i < N; i += 2) {
		if (is[i])
			prime[cnt++] = i;
	}
	return cnt;
}


void Init() {
	get_Prime();
	memset(num, 0, sizeof(num));
	num[0] = 1;
	num[1] = 1;
	for (int i = 0; i < cnt; i++) {
		for (ll j = prime[i]; j < N; j *= prime[i])
			num[j] = prime[i];
	}

	for (int i = 1; i < N; i++) {
		if (num[i] == 0) {
			num[i] = num[i - 1];
		}
		else 
			num[i] = (num[i - 1] * num[i]) % MOD;
	}
	for (int i = 1; i < N; i++) {
		num[i] = (num[i] * inv(i, MOD)) % MOD;
	}
}

int main() {

	int t;
	Init();
	scanf("%d", &t);

	while (t--) {
		int n;	
		scanf("%d", &n);
		printf("%lld\n", num[n + 1]);	
	}

	return 0;
}
