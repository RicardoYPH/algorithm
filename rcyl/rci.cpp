#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int C[55][55];
int prime[55];
bool is[55];
int cnt;

void Init() {
	memset(C, 0, sizeof(C));
	for (int i = 0; i <= 50; i++) 
		C[i][0] = 1;

	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= i; j++) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1]; 	
		}	
	}
	
	memset(is, 1, sizeof(is));
	cnt = 0;
	prime[cnt++] = 2;
	is[0] = is[1] = 0;

	int i, j;
	int s, e = sqrt(55);
	for (i = 4; i < 55; i += 2)
		is[i] = 0;

	for (i = 3; i < e; i += 2) {
		if (!is[i])
			continue;
		prime[cnt++] = i;
		for (s = i * 2, j = i * i; j < 55; j += s) {
			is[j] = 0;	
		}
	}

	for (; i < 55; i += 2) {
		if (is[i])
			prime[cnt++] = i;
	}
}

int main() {
	
	int k, s;
	Init();

	while (~scanf("%d%d", &k, &s)) {

		int Maxs = (1 << cnt);
		int ans = 0;

		for (int j = 1; j < Maxs; j++) {
			int pro = 1, total = 0;
			for (int i = 0; i < cnt; i++) {
				if (j & (1 << i)){
					total ++;	
					pro *= prime[i];
				}	
			}	


			if (total & 1) 
				ans += C[s / pro][k];
			else 
				ans -= C[s / pro][k];

			if (ans > 10000) {
				ans = 10000;
				break;
			}
		}
		printf("%d\n", ans);
	
	}

	return 0;
}
