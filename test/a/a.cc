#include <cstdio>
#include <cstring>
#include <bitset>
#include <cmath>

using namespace std;

const int N = 10000 + 10;

bitset<N> is;
int prime[N];
int cnt;


void getPrime() {
	int i, j;
	int s, e = sqrt(N);
	is.set();
	cnt = 0;
	prime[cnt++] = 2;
	is[0] = is[1] = 0;

	for (i = 4; i < N; i += 2) is[i] = 0;

	for (i = 3; i <= e; i += 2) if (is[i]) {
		prime[cnt++] = i;	

		for (j = i * i, s = i * 2; j < N; j += s) {
			is[j] = 0;	
		}
	}

	for (; i < N; i += 2) if(is[i]) {
		prime[cnt++] = i;	
	}
}

int main() {

	getPrime();


	int n;

	while(~scanf("%d", &n)) {
		int ans = 0;	
		for (int i = 0; i < cnt && prime[i] <= n; i++) {
			for (int j = i; j < cnt && prime[j] <= n - prime[i]; j++) {
				int tmp = n - prime[i] - prime[j];
				
				if (is[tmp] == 1 && tmp >= prime[j]) {
					ans++;	
				}
			
			}		
		}	

		printf("%d\n", ans);
	
	}


	
	return 0;
}
