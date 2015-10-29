#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 1e5 + 10;

int cnt[N];
int n;

int lowbit(int x) {
	return x & (-x);
}

void add(int x, int num) {
	while (x <= n) {
		cnt[x] += num;
		x = x + lowbit(x);
	}
}

int getSum(int x) {
	int res = 0;

	while (x > 0) {
		res += cnt[x];
		x = x - lowbit(x);
	}
	return res;
}

int main() {
	while (~scanf("%d", &n) && n) {

		memset(cnt, 0, sizeof(cnt));


		int s, e;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &s, &e);	
			cnt[s] += 1;
			cnt[e + 1] -= 1;
		}

		int sum = 0;
		for (int i = 1; i < n; i++) {
			sum += cnt[i];	
			printf("%d ", sum);
		}
		printf("%d\n", sum += cnt[n]);
/*	
		int s, e;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &s, &e);	
			add(s, 1);
			add(e + 1, -1);
		}

		for (int i = 1; i < n; i++) {
			printf("%d ", getSum(i));	
		}
		printf("%d\n", getSum(n));
*/	
	}

	return 0;
}
