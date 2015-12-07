#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1000000007;
const int N = 1e5 + 10;

char str[N];
ll num[N][3];

int main() {

	scanf("%s", str);
	
	int e = strlen(str);

	memset(num, 0, sizeof(num));
	ll tot = 0;
	for (int i = e - 1; i >= 0; i--) {
		if (str[i] == 'T') tot++;	
		if (str[i] == 'A') num[i][1] = tot;
	}
	tot = 0;
	for (int i = 0; i < e; i++) {
		if (str[i] == 'P') tot++;
		if (str[i] == 'A') num[i][2] = tot;
	}

	ll ans = 0;
	for (int i = 0; i < e; i++) {
		if (str[i] == 'A') {
			ans += (num[i][1] * num[i][2]) % mod;
			ans %= mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
