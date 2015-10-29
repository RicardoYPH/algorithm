#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;
double t;
int prime[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};


LL dfs(int index, LL x) {
	if (x > 60) {
		return 0;		
	}
	LL ret = 0;	

	for (int i = index; i < 17; i++) {
		LL tmp = (LL)(pow(t, 1.0 /(x * prime[i])) + 1e-8) - 1;
		ret += tmp - dfs(i + 1, x * prime[i]);
	}
	return ret;
}


int main() {


	while (~scanf("%lf", &t)) {
		printf("%lld\n", dfs(0, 1) + 1);			
	
	}


	return 0;
}
