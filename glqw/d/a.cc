#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 110;

int main() {

	int t;
	scanf("%d", &t);

	double mp;
	int n;
	double p[N];
	int m[N];
	double dp[N * N];

	int CASE = 1;

	while(t--) {
		scanf("%lf%d", &mp, &n);	
		int sum = 0;
		int i, j;

		for (i = 1; i <= n; i++) {
			scanf("%d%lf", m + i, p + i);	
			sum += m[i];
		}

		memset(dp, 0, sizeof(dp));

		dp[0] = 1;

		//01背包

		for (i = 1; i <= n; i++) {
			for (j = sum; j >= m[i]; j--) {
				dp[j] = max(dp[j], dp[j - m[i]] * (1 - p[i]));
			}	
		}
/*
		for (i = 0; i <= sum; i++) {
			printf("%lf\n", dp[i]);	
		}
*/
		for (i = sum; i >= 0; i--) {
			if (dp[i] > 1 - mp) {
				break;	
			}		
		}
		printf("Case %d: %d\n", CASE++, i);
	}
	return 0;
}
