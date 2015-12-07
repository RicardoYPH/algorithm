#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int e = sqrt(n) + 1;
	int anss = 0, ansn = 0;
	for (int i = 2; i <= e; i++) {
		int tn = n, ti = i;
		if (tn % ti == 0) {
			while (tn % ti == 0) {
				tn /= ti++;
			}
			if (ti - i > ansn) {
				ansn = ti - i;
				anss = i;
			}
		}
	}
	if (ansn == 0) {
		ansn = 1;
		anss = n;
	}
	printf("%d\n", ansn);
	printf("%d", anss);
	for (int i = 1; i < ansn; i++) {
		printf("*%d", anss + i);
	}
	puts("");
	return 0;
}
