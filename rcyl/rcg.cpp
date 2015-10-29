#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int lnum[20];
int unum[510];
int nl, nu;
LL l, h;

LL gcd (LL a, LL b) {
	return b == 0 ? a : gcd (b, a % b);
}

LL lcm (LL a, LL b) {
	LL g = gcd (a, b);
	if (a / g > h / b)  
		return h + 1;
	return a / g * b;
}

LL getNum(LL tmp) {
	LL ret = 0;	
	int Maxs = (1 << nl);
	for (int s = 1; s < Maxs; s++) {
		LL pro = 1, total = 0;	
		for (int i = 0; i < nl; i++) {
			if (s & (1 << i)) { 
				total++;	
				pro = lcm(pro, lnum[i]);
			}	
		}
		LL g = lcm(pro, tmp);
		if (total & 1) {
			ret += h / pro - h / g - ((l - 1) / pro - (l - 1) / g);	
		}
		else {
			ret -= h / pro - h / g - ((l - 1) / pro - (l - 1) / g);	
		}
	}
	return ret;
}


int main() {

	while (~scanf("%d%d%lld%lld", &nl, &nu, &l, &h)) {	
		if (nl == 0 && nu == 0 && l == 0 && h == 0) 
			break;
		for (int i = 0; i < nl; i++) {
			scanf("%d", &lnum[i]);	
		}
		for (int i = 0; i < nu; i++) {
			scanf("%d", &unum[i]);	
		}
		LL tmp = unum[0];
		for (int i = 1; i < nu; i++) {	
			tmp = lcm(tmp, unum[i]);
		}
		LL ans = getNum(tmp);
		printf("%lld\n", ans);	
	}

	return 0;
}
