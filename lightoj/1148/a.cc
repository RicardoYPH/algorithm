#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 51;

struct node {
	ll num, tot;
};

node data[N];

int main() {
	int t;
	scanf("%d", &t);
	int CASE = 1;
	while (t--) {
		for (int i = 1; i < N; i++) {
			data[i].num = data[i].tot = 0;
		}
		int n;
	   	ll tmp;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &tmp);
			tmp += 1;
			for (int j = 1; j < N; j++) {
				if (data[j].num == tmp || data[j].num == 0){
					data[j].num = tmp;
					data[j].tot ++;
					break;
				}
			}
		}
		ll ans = 0;
		for (int j = 1; j < N; j++) {
			if (data[j].num == 0) break;
			ans += (data[j].tot / data[j].num + (ll)(data[j].tot % data[j].num != 0) ) * data[j].num;
		}
		printf("Case %d: %lld\n", CASE++, ans);

	}
	return 0;
}
