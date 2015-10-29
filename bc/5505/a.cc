#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned long long ll;

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {
		ll n, m;
		scanf("%llu%llu", &n, &m);
		if (m == n) {
			printf("0\n");
			continue;
		}
		if (n == 0 || n == 1) {
			cout << -1 << endl;
			continue;
		}
		if (m % n != 0) {
			cout << -1 << endl;
			continue;
		}
		int cnt = 0;

		m = m / n;

		while (m % n == 0) {
			m /= n; 
			n *= n;
			cnt++;
		}

		ll tmp = __gcd(n, m);
		while (tmp != 1) {
			m = m / tmp;
			n *= tmp;
			cnt++;
			tmp = __gcd(n, m);
		}
		if (m == 1) {
			printf("%d\n", cnt);
		}
		else {
			printf("-1\n");
		}


	}
	

	return 0;
}
