#include <cstdio>

const int MOD = 1000003;

typedef long long ll;

ll ans[MOD + 10];

int main() {

	ans[1] = 2;

	for (int i = 2; i <= MOD; i++) 
		ans[i] = (ans[i - 1] * i * 2) % MOD;
	

	int t;

	scanf("%d", &t);

	while (t--) {
	
		ll n;

		scanf("%lld", &n);
		if (n == 0) 
			printf("1\n");

		if (n >= MOD)
			printf("0\n");
		else 
			printf("%lld\n", ans[n]);
		
	}


	return 0;
}
