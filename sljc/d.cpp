#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

int main() {
	

	int t;

	int CASE = 1;
	scanf("%d", &t);
	
	while (t--) {

		LL tmp;

		scanf("%lld", &tmp);

		LL ans;

		ans = (LL) sqrt(tmp);
		ans += (LL) sqrt(tmp / 2.0);


		printf("Case %d: %lld\n", CASE++, tmp - ans);


	
	}

	return 0;
}



/*

typedef long long LL;

const int LEN  = 1000;

bool is[LEN];
int prime[LEN];

int getPrime() {	

	int i, j, k = 0;
	int s, e = (int) sqrt(0.0 + LEN) + 1;

	memset(is, 1, sizeof(is));

	prime[k++] = 2;
	is[0] = is[1] = 0;

	for (i = 4; i < LEN; i += 2) 
		is[i] = 0;

	for(i = 3; i < e; i += 2) {
		if (! is[i]) 
			continue;
		prime[k++] = i;
		for (s = i * 2, j = i * i; j < LEN; j += s) {
			is[j] = 0;
		}
		for (; i < LEN; i += 2) 
			if (is[i])
				prime[k++] = i;

	} 
	return k;

}

int main() {

	int k = getPrime();

	for (int i = 1; i < LEN; i++) {
		LL ans = 1;
		int tmp = i;

		for (int j = 0; j < k && prime[j] * prime[j] <= tmp; j++) {

			int c = 1;
			if(tmp % prime[j]) 
				continue;
			while (tmp % prime[j] == 0) {
				c++;
				tmp /= prime[j];
			}
				
			ans = ans * (pow(prime[j], c) - 1) / (prime[j] - 1);

		}
		if (tmp > 1) 
			ans = ans * (pow(tmp, 2) - 1) / (tmp - 1);

	
		ans = ans % 2;
		printf("%d %lld\n", i, ans);
	}	

	return 0;
}*/
