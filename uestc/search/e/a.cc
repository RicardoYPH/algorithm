#include <bits/stdc++.h>

using namespace std;

const int N = 70;

int a[N];

int main() {

	int n;
	while (~scanf("%d", &n) && n) {

		int sum = 0;

		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			sum += a[i];
		}

	}


	return 0;
}
