#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 80000; 

bool is[N];
int cnt = 0;
ll prime[N];
bool isprime[100010];

void getPrime() {
	int i, j, s, e = sqrt(N);
	memset(is, true, sizeof(is));
	cnt = 0;
	is[0] = is[1] = false;
	prime[cnt++] = 2;
	for (i = 4; i < N; i += 2) is[i] = false;

	for (i = 3; i <= e; i += 2) if (is[i]) {
		prime[cnt++] = i;
		for (j = i * i, s = i + i; j < N; j += s) 
			is[j] = false;
	}
	for (; i < N; i += 2) if (is[i]) 
		prime[cnt++] = i;
}

ll getAns(ll a, ll b) {
	if (a == 1) a = 2;
	int end = cnt;
	memset(isprime, true, sizeof(isprime));
	ll k;
	for (int i = 0; i < end && prime[i] * prime[i] <= b; i++) {
		k = a / prime[i];
		if (k * prime[i] < a) k++;
		if (k <= 1) k++;
		while (k * prime[i] <= b) {
			isprime[k * prime[i] - a] = false;
			k++;
		}
	}
	ll ans = 0;
	for (ll i = 0; i <= b - a; i++) if (isprime[i]) {
		ans++;
	}
	return ans;
}


int main() {
	int t;
	getPrime();
	scanf("%d", &t);
	int CASE = 1;
	while (t--) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		printf("Case %d: %lld\n", CASE++, getAns(a, b));
	}
	return 0;
}
