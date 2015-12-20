#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	while (~scanf("%d", &n)) {
		int ans = -1;
		int flag = 0;
		for (int i = n - 70; i <= n; i++) {
			int tmp = i;
			ans = 0;
			while (tmp != 0) {
				ans += tmp % 10;
				tmp /= 10;
			}
			if (i + ans == n) {
				flag = 1;
				ans = i;
				break;
			}
		}
		if (flag == 1) printf("%d\n", ans);
		else printf("0\n");
	}

	return 0;
}
