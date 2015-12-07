#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int h[N];

int main() {
	int n;
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) scanf("%d", h + i);

	int now = 0;
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (h[i] > now) {
			ans += (h[i] - now) * 6 + 5;
		}
		else {
			ans += (now - h[i]) * 4 + 5;
		}
		now = h[i];
	}
	cout << ans << endl;


	return 0;
}
