#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long LL;

LL total[70];

LL getData(LL s) {
	if (s <= 1) 
		return 0;
	LL ret = 0;
	total[1] = s - 1;
	for (int i = 60; i >= 2; i--) {
		total[i] = (LL) (pow ((double)s, 1.0 / i) + 1e-8);
		while (1) {
			int j = i;	
			LL tmp = 1;
			while (j--) {
				tmp *= total[i];
			}
			if (tmp <= s) {
				break;	
			}
			total[i]--;
		}
		total[i]--;
	}
	for (int i = 60; i >= 1; i--) {
		for (int j = i + i; j <= 60; j += i) {
			total[i] -= total[j];	
		}
		ret += total[i] * i;
	}
	return ret;
}

int main () {
	LL s, e;
	LL ans;

	while(~scanf("%lld%lld", &s, &e)) {
		ans = 0;
		if (s == 0 && e == 0) 
			break;
		ans = getData(e) - getData(s - 1);
		printf("%lld\n", ans);
	}
	return 0;
}
