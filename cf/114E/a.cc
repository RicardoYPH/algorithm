#include <cstdio>
#include <cstring>
#include <bitset>
#include <cmath>

using namespace std;

const int N = 3 * 1e8 + 10;

bitset<N> prime;

//bool prime[N];


int main() {
	
	int l, r;

	while(~scanf("%d%d", &l, &r)) {

		prime.set();

//		memset(prime, true, sizeof(prime));
		int e = sqrt(r) + 1;

		for (int i = 3; i <= e; i += 2)
			if (prime[i]) 
				for (int j = i * i, s = i * 2; j <= r; j += s) {
					prime[j] = false;	
				}

		int cnt = (l <= 2 && 2 <= r);
		for (int i = 5; i <= r; i += 4)
			if (i >= l && prime[i]) 
				cnt ++;


		printf("%d\n", cnt);
	
	}



	return 0;
}
