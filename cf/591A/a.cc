#include <bits/stdc++.h>

using namespace std;

const int N = 5 * 1e5 + 10;

int a[N];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}

	int flag = 0;

	vector <int> s;
	vector <int> e;

	for (int i = 2; i < n; i++) {
		if (a[i] != a[i - 1] && a[i] != a[i + 1]) {
			if (flag == 0) {
				s.push_back(i - 1); 
				flag = 1;
			}
		}
		else {
			if (flag == 1) {
				e.push_back(i);
				flag = 0;
			}
		}
	}
	if (flag == 1) {
		e.push_back(n);
	}
	int ans = 0;

	int size = s.size();

	for (int i = 0; i < size; i++) {
		ans = max(ans, (e[i] - 1 - s[i] - 1 + 2) / 2);
		if (a[e[i]] == a[s[i]]) {
			for(int j = s[i] + 1; j < e[i]; j++) {
				a[j] = a[s[i]];
			}
		}	
		else {
			int mid = (e[i] + s[i]) / 2;
			for (int j = s[i] + 1; j <= mid; j++) {
				a[j] = a[s[i]];
			}
			for (int j = mid + 1; j < e[i]; j++){
				a[j] = a[e[i]];
			}
		}
	}

	printf("%d\n", ans);
	printf("%d", a[1]);

	for (int i = 2; i <= n; i++) {
		printf(" %d", a[i]);
	}
	printf("\n");

	
	return 0;
}
