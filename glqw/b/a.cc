#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	int a[110];

	double dp[110];

	int CASE = 1;

	while (t--) {
		int n;

		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);	
		}

		dp[n] = a[n];

		for (int i = n - 1; i > 0; i--) {
			double div = min(6, n - i);	
			double sum = 0;

			for (int j = 1; j <= div; j++) {
				sum += dp[i + j];	
			}
			dp[i] = sum / div + a[i];
			sum += dp[i];
		}

		printf("Case %d: %lf\n", CASE++, dp[1]);

	
	
	}


	return 0;
}
