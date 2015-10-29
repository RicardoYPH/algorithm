#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL dp[70];

int main() {
	
	int t;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < 70; i++) {
		dp[i] = dp[i - 1] + 1 + dp[i - 3];	
	}

	while (~scanf("%d", &t)) {
		printf("%lld\n", dp[t]);	
				
	}	

	return 0;
}
