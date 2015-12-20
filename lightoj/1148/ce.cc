#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int main() {

	int t = 100;
	printf("%d\n", t);
	
	srand(time(NULL));
	for (int i = 1; i <= t; i++) {
		int n = rand() % 50 + 1;
		printf("%d\n", n);

		int tmp = n;
		int cnt = 1;

		while (tmp != 0) {
			int t = rand() % tmp + 1;
			int num = rand() % 10 + 1;
			for (int i = 1; i <= t; cnt ++, i++) {
				printf("%d%c", num , cnt == n ? '\n' : ' ');	
			}
			tmp -= t;
		}

	}
	return 0;
}
