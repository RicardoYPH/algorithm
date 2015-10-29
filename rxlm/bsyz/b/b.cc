#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 50010;
long long n;
typedef long long LL;
long long num[N];
LL dp[N];
double OR() {
	memset(dp, 0, sizeof(dp));
	long long sum = 0;
	long long all = (LL)n*(n+1)/2;
	double res = 0;
	for(int i=0; i<30; i++){
		sum = 0;
		for(int j = 1; j <= n; j ++){
			if(num[j]&(1LL<<i)) dp[j] = j;
			else dp[j] = dp[j-1];
			sum += dp[j];
		}
		res += (LL)(1LL<<i)*(sum*1.0/all);
	}
	return res;
}
double AND() {
	memset(dp, 0, sizeof(dp));
	long long sum = 0;
	long long all = (LL)n*(n+1)/2;
	double res = 0;
	for(int i=0; i<30; i++){
		sum = 0;
		for(int j = 1; j <= n; j ++){
			if(num[j]&(1LL<<i)) dp[j] = dp[j-1] + 1;
			else dp[j] = 0;
			sum += dp[j];
		}
		res += (LL)(1LL<<i)*(sum*1.0/all);
	}
	return res;
}
double XOR() {
	memset(dp, 0, sizeof(dp));
	long long sum = 0;
	long long all = (LL)n*(n+1)/2;
	double res = 0;
	for(int i=0; i<30; i++){
		sum = 0;
		for(int j = 1; j <= n; j ++){
			if(num[j]&(1LL<<i)) dp[j] = j - dp[j-1];
			else dp[j] = dp[j-1];
			sum += dp[j];
		}
		res += (LL)(1LL<<i)*(sum*1.0/all);
	}
	return res;
}

int main() {
	int T, tt = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &num[i]);
		printf("Case #%d: %.6f %.6f %.6f\n", tt++, AND(), OR(), XOR());
	}
	return 0;
}
