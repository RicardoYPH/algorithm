#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 510;

int main() {
	
	int t;
	scanf("%d", &t);

	int a[N];
	int b[N];


	while (t--) {
	
		int n, m;
		scanf("%d%d", &n, &m);

		for (int i = 0; i < n; i++) 
			scanf("%d", a + i);

		for (int i = 0; i < n; i++) 
			scanf("%d", b + i);


		sort(a, a + n);
		sort(b, b + n);



		int ta, tb;
		ta = tb = 0;
		for (int i = 0; i < m; i++) {
			ta += a[i];	
			tb += b[n - i - 1];
		}

		if (ta > tb) 
			printf("YES\n");
		else 
			puts("NO");


	
	}

	return 0;
}

