#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int v[N];

ll Max(ll a, ll b) {
	return a > b ? a : b;
}

ll getV(int s, int e) {

	ll ret = 0;
	for (int i = s; i <= e; i++)
		ret += v[i];
	return ret;
}

int main() {
	int n, p;
	int m, t;
		
	while (scanf("%d%d", &n, &p) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", v + i);	
		}	
		scanf("%d%d", &m, &t);
		int m = m / 2;				
		
		int s, e;
		ll ans;
		s = Max(1, p - t);
		e =	Min(n, p + t); 

		printf("%lld\n", ans);
	
	}

	

	return 0;
}
