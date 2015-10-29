#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
int data[12];
int n, m;

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd (b, a % b);

}

LL lcm(LL a, LL b) {
	return a * b / gcd(a, b);
}

int dfs(int loc, LL t) {
	LL tmp = 0;
	if (t > n)
		return 0;
	for (int i = loc; i < m; i++) {
		LL lc = lcm(t, data[i]);
		tmp += (n - 1) / lc;	
		tmp -= dfs(i + 1, lc);

//		tmp += (n - 1) / (t * data[i]);
//		tmp -= dfs(i + 1, t * data[i]);
	}
	return tmp;
}
int main() {

	while (~scanf("%d%d", &n, &m)) {
		LL ans = 0;
		int i;
		int index = 0;
		for (i = 0; i < m; i++) {
			scanf("%d", &data[index]);		
			if (data[index] != 0) 
				index++;
		}	
		m = index;

		ans += dfs(0, 1);
		printf("%lld\n", ans);
	
	}

	return 0;
}
