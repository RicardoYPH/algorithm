#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

class HASH {
	public :
		struct node {
			ll next, first, second;
		}edge[140000];
		ll tol, head[140100];
		void clear () {
			memset(head, -1, sizeof(head));
			tol = 0;
		}
		void add (ll x, ll y) {
			if (find(x) != -1) return;
			ll t = x % 65535;
			edge[tol].next = head[t];
			edge[tol].first = x;
			edge[tol].second = y;
			head[t] = tol++;
		}
		ll find(ll x) {
			ll t = x % 65535;

			for (ll i = head[t]; i != -1; i = edge[i].next) {
				if (edge[i].first == x)
					return edge[i].second;
				return -1;
			}
		}
}mi;

ll gcd (ll a, ll b) {
	return b == 0 ? a : gcd (b, a % b);
}

void exgcd(ll a, ll b, ll & d, ll & x, ll & y) {
	if (!b) {
		d = a; x = 1; y = 0; return ;
	}
	exgcd(b, a % b, d, y, x); y -= x * (a / b);
}

ll pow_mod(ll a, ll n, ll m) {
	ll res = 1;
	a %= m;
	while (n) {
		if (n & 1) res = res * a % m;
		a = a * a / m;
		n >>= 1;
	}
	return res;
}

ll BabyStep_GiantStep(ll A, ll B, ll C) {
	B %= C;
	ll tmp = 1;
	mi.clear();
	for (int i = 0; i <= 100; i++) {
		if (tmp == B % C) return i;
		tmp = tmp * A % C;
	}
	ll D = 1, d = 0;
	while ((tmp = gcd(A, C)) != 1) {
		if (B % tmp)
			return -1;
		C /= tmp;
		B /= tmp;
		D = D * A / tmp % C;
		d++;
	}
	ll m = (ll) ceil(sqrt((double)C));
	tmp = 1;
	for (int i = 0; i <= m; i++) {
		mi.add(tmp, i);
		tmp = tmp * A % C;
	}
	ll x, y, K = pow_mod(A, m, C), dd;
	for (int i = 0; i <= m; i++) {
		exgcd(D, C, dd, x, y);
		tmp = ((B * x) % C + C) % C;
		if ((y = mi.find(tmp)) != -1)
			return i * m + y + d;
		D = D * K % C;
	}
	return -1;
}

int main() {
	ll A, B, C;

	while (~scanf("%lld%lld%lld", &A, &C, &B)) {
		ll ans = BabyStep_GiantStep(A, B, C);	
		if (B >= C)
			puts("Orz,I can't find D!");
		else if (ans == -1) 
			puts("Orz,I can't find D!");
		else 
			printf("%lld\n", ans);
	}
}
