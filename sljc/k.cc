#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
	int t;
	scanf("%d", &t);

	char a[210];
	ll mod;
	int CASE = 1;

	while(t--) {

		scanf("%s%lld", a, &mod);

		int len = strlen(a);

		ll tmp;

		int i = 0;
		while (a[i] < '0' || a[i] > '9')
			i++;

		ll ans = 0;
		for (; i < len; i++) {
			ans = ((ans * 10) % mod + a[i] - '0') % mod;
		}
		if (ans == 0) 
			printf("Case %d: divisible\n", CASE++);
		else 
			printf("Case %d: not divisible\n", CASE++);

			
	
	}

	return 0;
}
