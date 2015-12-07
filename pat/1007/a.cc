#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
int num[N];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) 
		scanf("%d", num + i);
	int ts = 1, tot = num[1];
	int ans = num[1], s = 1, e = 1;
	for (int i = 2; i <= n; i++) {
		if (tot < 0) {
			tot = num[i];
			ts = i;
			if (tot > ans) {
				ans = tot;
				s = ts;
				e = i;
			}
		}
		else {
			tot += num[i];
			if (tot > ans) {
				ans = tot;
				s = ts;
				e = i;
			}
		}
	}
	if (ans < 0) {
		printf("0 %d %d\n", num[1], num[n]);
	}
	else 
		printf("%d %d %d\n", ans, num[s], num[e]);


	return 0;
}
