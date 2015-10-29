#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

int const LEN = 1e6 + 10;

bool is[LEN];
int prime[LEN/5];

int getPrime() {
	int i, j, k = 0;

	int s, e = (int)sqrt(0.0 + LEN) + 1;

	memset(is, 1, sizeof(is));
	prime[k++] = 2;
	is[0] = is[1] = 0;

	for (i = 4; i < LEN; i += 2) 
		is[i] = 0;

	for (i = 3; i < e; i += 2) {
		if (!is[i])
			continue;
		prime[k++] = i;	
		for (s = i * 2, j = i * i; j < LEN; j += s) 
			is[j] = 0;
	}
	for (; i < LEN; i += 2) 
		if (is[i]) 
			prime[k++] = i;
	return k;
}

int main() {
	int MAX = getPrime();
	int t;
	scanf("%d", &t);
	int CASE = 1;

	while (t--) {
		LL a, b;		
		scanf("%lld%lld", &a, &b);	
		if (a <= b * b)  {
			printf("Case %d: 0\n", CASE++);
			continue;
		}

		LL tmp = a;
		LL num = 1;;
		for (int i = 0; i < MAX && prime[i] * prime[i] <= tmp; i++) {
			int c = 1;
			while (tmp % prime[i] == 0) {
				tmp /= prime[i];
				c++;
			}
			num *= c;
		}
		if (tmp > 1) 
			num *= 2;

		num /= 2;

		for (int i = 1; i < b; i++) 
			if (a % i == 0) 
				num--;

		printf("Case %d: %lld\n", CASE++, num);
	
	}


	return 0;
}
