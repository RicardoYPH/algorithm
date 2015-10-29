#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 5 * 1e6 + 10;

bool is[N];
int prime[N / 10];
int cnt;

void getPrime() {
	int i, j;
	int s, e = (int)sqrt(N);
	cnt = 0;
	memset(is, 1, sizeof(is));

	prime[cnt++] = 2;
	is[0] = is[1] = 0;

	for (i = 4; i < N; i += 2)
		is[i] = 0;
	for (i = 3; i <= e; i += 2) if(is[i]) {
		prime[cnt++] = i;	
		for (s = i * 2, j = i * i; j < N; j += s)
			is[j] = 0;
	}
	for (; i < N; i += 2) 
		if (is[i])
			prime[cnt++] = i;
} 

int main() {

	int l, r;
	getPrime();

	while (~scanf("%d%d", &l, &r)) {
		int i;
		for (i = 0; i < cnt; i++) 
			if(prime[i] >= l)
				break;
		int Max, Min;
		if (prime[i + 1] > r) {
			printf("There are no adjacent primes.\n");
			continue;
		}
	
		Max = Min = prime[i + 1] - prime[i];
		int MaxIN, MinIN;
		MaxIN = MinIN = i + 1;

		for (i = i + 2; prime[i] <= r && i < cnt; i++) {
			int tmp = prime[i] - prime[i - 1];	
			if (Max < tmp) {
				Max = tmp;
				MaxIN = i;
			}
			if (Min > tmp) {
				Min = tmp;
				MinIN = i;
			}
		}

		printf("%d,%d are closest, %d,%d are most distant.\n", prime[MinIN - 1], prime[MinIN], prime[MaxIN - 1], prime[MaxIN]);


	
	}

	return 0;
}
