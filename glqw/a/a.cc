#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int a[110];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {

	int t;
	scanf("%d", &t);

	int CASE = 1;

	while (t--) {
		int n;
		scanf("%d", &n);

		int sum = 0, total = 0;
		for (int i= 1; i <= n; i++) {
			scanf("%d", a + i);
			if (a[i] > 0) {
				sum += a[i];	
				total++;
			}
			else 
				sum += -a[i];
		}

		if (total == 0) {
			printf("Case %d: inf\n", CASE++);	
		}
		else {
			int t = gcd(total, sum);	
			printf("Case %d: %d/%d\n", CASE++, sum / t, total / t);
		}


	
	
	}

	
	return 0;
}
