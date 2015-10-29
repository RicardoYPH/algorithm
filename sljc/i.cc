#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 1e6 + 10;

double num[MAXN];

int main() {
	double tmp = 0;
	num[0] = 0;
	for (int i = 1; i < 100000010; i++) {
		tmp = tmp + 1.0 / i;
		if (i % 100 == 0) 
			num[i / 100] = tmp;
	}

	int t;
	scanf("%d", &t);

	int CASE = 1;

	while (t--) {
		int n;
		scanf("%d", &n);

		int loc = n / 100;
		double ans = num[loc];	
		for (int i = loc * 100 + 1; i <= n; i++) {
			ans = ans + 1.0 / i;
		}

		printf("Case %d: %.10lf\n", CASE++, ans);
	
	}

	return 0;
}



/*
const int MAXN = 1e6 + 10;
const double phi = 0.57721566490153286060651209;

double num[MAXN];

int main() {

	num[1] = 1;

	for (int i = 2; i < MAXN; i++) {
		num[i] = num[i - 1] + 1.0 / i;	
	}
	int t;
	scanf("%d", &t);

	int CASE = 1;

	while (t--) {
		int n;
		scanf("%d", &n);

		double ans = 0;

		if (n < MAXN)
			ans = num[n];
		else 
			ans = log(n + 0.5) + phi;

		printf("Case %d: %.10lf\n", CASE++, ans);

		
	}

	return 0;
}*/
