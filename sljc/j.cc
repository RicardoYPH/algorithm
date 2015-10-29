#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

const ll N = 1000010;
bool is[N];
ll prime[N];
int cnt;

void getPrime() {
	int i, j;
	int s, e = sqrt(N);
	memset(is, 1, sizeof(is));
	memset(prime, 0, sizeof(prime));
	cnt = 0;
	is[0] = is[1] = 0;
	prime[cnt++] = 2;

	for (i = 4; i < N; i += 2) 
		is[i] = 0;
	for (i = 3; i < e; i += 2) 
		if (is[i]) {
			prime[cnt++] = i;	
			for (s = i * 2, j = i * i; j < N; j += s)
				is[j] = 0;
		}

	for (; i < N; i += 2) 
		if (is[i])
			prime[cnt++] = i;
}

int gcd (int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	getPrime();
	int t;
	scanf("%d", &t);
	vector <ll> V;
	int CASE = 1;
	while (t--) {
		V.clear();
		ll n;
		bool flag = true;

		scanf("%lld", &n);
		if (n < 0) {
			n = -n;
			flag = false;
		}
		for (ll i = 0; i < cnt && prime[i] < n; i++) {	
			if (n % prime[i])
				continue;
			ll tmp = 0;
			while (n % prime[i] == 0) {
				tmp++;
				n /= prime[i];
			}
			V.push_back(tmp);
		}
		if (n > 1) 
			V.push_back(1);
		
		ll ans = V[0];

		for (int i = 1; i < V.size(); i++) {
			ans = gcd(ans, V[i]);	
		}
		if (flag == false) 
			while (ans % 2 == 0)
				ans = ans / 2;

		printf("Case %d: %lld\n", CASE++, ans);
		
	}

	return 0;
}
