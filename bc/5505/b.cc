#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

typedef unsigned long long ll;

const int N = 1e6 + 10;

bool is[N];
int prim[N / 10];
int cnt;

void getPrim() {
	int i, j;
	int s, e = sqrt(N);
	cnt = 0;
	memset(is, 1, sizeof(is));
	prim[cnt++] = 2;
	is[0] = is[1] = 0;

	for (i = 4; i < N; i += 2) is[i] = 0;

	for (i = 3; i <= e; i += 2) if(is[i]) {
		prim[cnt++] = i;

		for (j = i * i, s = i + i; j < N; j += s) 
			is[j] = 0;
	}
	for (; i < N; i += 2) 
		if (is[i]) 
			prim[cnt++] = i;
}
int getNum(ll a, int b) {
	int res = 0;

	while (a % b == 0 && a > 0) {
		res++;
		a /= b;
	}
	return res;
}

int main() {

	getPrim();

	int t;
	scanf("%d", &t);

	while (t--) {
	
		ll n, m;	
		scanf("%llu%llu", &n, &m);

		int Max = 0;
		int i;
		int flag = 0;

		for (i = 0; i < cnt && (prim[i] <= n || prim[i] <= m); i++) {
			if (n % prim[i] == 0 || m % prim[i] == 0){
				int num1 = getNum(n, prim[i]);			
				int num2 = getNum(m, prim[i]);
				if (num1 == 0 && num2 == 0) {
					continue;
				}			
				if (num1 == 0) {
					flag = 1;
					break;
				}
				if (num1 > num2) {
					flag = 1;
					break;
				}	

				int tot = 0;

				while (num2 > num1) {
					num1 *= 2;
					tot++;
				}

				Max = max(Max, tot);
				while (n % prim[i] == 0 && n > 0) 
					n /= prim[i];
				while (m % prim[i] == 0 && m > 0) 
					m /= prim[i];
			}
			if (flag)
				break;
		}
		if (flag || m != 1) {
			printf("-1\n");
		}
		else {
			printf("%d\n", Max);
		}
	}

	
	return 0;
}
