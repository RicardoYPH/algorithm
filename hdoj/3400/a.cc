#include <bits/stdc++.h>

using namespace std;
const int N = 10;

struct point {
	double x, y;
}points[N];
double p, q, r;

int main() {

	int t;
	scanf("%d", &t);

	while (t--) {
		for (int i = 1; i <= 4; i++) {
			scanf("%lf%lf", points[i].x, points[i].y);
		}	

	}

	return 0;
}
