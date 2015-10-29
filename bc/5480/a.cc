#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

const int N = 1e5 + 10;

int main() {

	int t;
	scanf("%d", &t);

	int r[N];
	int c[N];

	while (t--) {
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		int n, m, k, q;	
		scanf("%d%d%d%d", &n, &m, &k, &q);

		int x, y;

		for (int i = 0; i < k; i++) {
			scanf("%d%d", &x, &y);
			r[x] = 1;
			c[y] = 1;
		}

		for (int i = 2; i <= n; i++) 
			r[i] += r[i - 1];

		for (int i = 2; i <= m; i++) 
			c[i] += c[i - 1];	


		int x1, y1, x2, y2;
		for (int i = 0; i < q; i++) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);	
			if (x2 - x1 + 1 == r[x2] - r[x1 - 1] || y2 - y1 + 1 == c[y2] - c[y1 - 1]) {
				printf("Yes\n");		
			}
			else {
				printf("No\n");
			}
		}




	
	}

	return 0;
}
