#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int LEN = 1e7 + 10;

int cnt;
bool is[LEN];
int prime[LEN /10];

void getPrime() {
	int n = LEN;
	int i, j;
	int s, e = sqrt(n);
	memset(is, 1, sizeof(is));
	cnt = 0;
	prime[cnt++] = 2;
	is[0] = is[1] = 0;

	for (i = 4; i < n; i += 2) 
		is[i] = 0;

	for (i = 3; i < e; i += 2) {
		if (!is[i])
			continue;
		prime[cnt++] = i;

		for (s = i * 2, j = i * i; j < n; j += s) {
			is[j] = 0;	
		}
	}
	for (;i < n; i+= 2) 
		if (is[i])
			prime[cnt++] = i;
}

int getIndex(int data) {
	
	int l = 0, r = cnt;
	while (l < r - 1) {
//		printf("l = %d r = %d tmp = %d\n", l, r, data);
//		getchar();
		int mid = (l + r) >> 1;
		if (prime[mid] <= data)
			l = mid;
		else 
			r = mid;
	}

	return l;

}


int main() {

	int t;
	getPrime();
	scanf("%d", &t);

	int CASE = 1;
	while (t--) {
		int tmp;
		scanf("%d", &tmp);
		tmp = tmp / 2;

		int loc = getIndex(tmp);
		int ans = 0;

		for (int i = loc; i >= 0; i--) {
			if (is[tmp * 2 - prime[i]]) {
				ans ++;
			}
		}
		printf("Case %d: %d\n", CASE++, ans);
			
	}

	return 0;
}
