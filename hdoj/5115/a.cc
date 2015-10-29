#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 210;

ll a[N];
ll b[N];

ll dp[N][N];

ll Min(ll a, ll b) {
	return a < b ? a : b;
}

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {


		int n;
		scanf("%d", &n);
		
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));

		for (int i = 1; i <= n; i++) 
			scanf("%lld", a + i);

		for (int i = 1; i <= n; i++) 
			scanf("%lld", b + i);

		memset(dp, 0x3f, sizeof(dp));

		for (int i = 1; i <= n; i++) 
			dp[i][i] = a[i] + b[i - 1] + b[i + 1];

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				dp[i][j] = Min(dp[i][j], a[i] + dp[i + 1][j] + b[i - 1] + b[j + 1]);
				dp[i][j] = Min(dp[i][j], a[j] + dp[i][j - 1] + b[i - 1] + b[j + 1]);
				for (int k = j - 1; k > i; k--) {
					dp[i][j] = Min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[k] + b[i - 1] + b[j + 1]);
				}
			}
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) 
				printf("%lld ", dp[i][j]);
			puts("");
		}
		memset(dp, 0x3f, sizeof(dp));

		for (int i = 1; i <= n; i++) 
			dp[i][i] = a[i] + b[i - 1] + b[i + 1];

		for (int l = 1; l < n; l++) 
			for (int i = 1; i + l <= n; i++) {
				int j = i + l;
				dp[i][j] = Min(a[i] + dp[i + 1][j] + b[i - 1] + b[j + 1], a[j] + dp[i][j - 1] + b[i - 1] + b[j + 1]);	
				for (int k = i + 1; k < j; k++) 
					dp[i][j] = Min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[k] + b[i - 1] + b[j + 1]);
			}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) 
				printf("%lld ", dp[i][j]);
			puts("");
		}

		printf("%lld\n", dp[1][n]);
	}

	
	return 0;
}
