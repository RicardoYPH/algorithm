#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 55;

int main() {

	int n;
	scanf("%d", &n);
	int a[N], b[N], c[N];

	int tmp;
	a[0] = b[0] = c[0] = 0;
	for (int i = 1; i < n; i++) {
		scanf("%d", &tmp);
		a[i] = a[i - 1] + tmp;
	}

	for (int i = 1; i < n; i++) {
		scanf("%d", &tmp);
		b[i] = b[i - 1] + tmp;
	
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
	}

	for (int i = 1; i <= n; i++) {
		c[i] += a[i - 1] + b[n - 1] - b[i - 1];
	}

	sort (c + 1, c + 1 + n);

	printf("%d\n", c[1] + c[2]);
	
	return 0;
}
