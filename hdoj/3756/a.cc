#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 10;
const double eps = 1e-5;

double x[N], y[N], z[N];
int n;

double getR(double h) {
	double Max = 0;
	for (int i = 1; i <= n; i++) {
		double t = h / (h - z[i]);
		double tx = x[i] * t;
		double ty = y[i] * t;
		Max = max(tx * tx + ty * ty, Max);
	}
	return sqrt(Max);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		double l, r;
		l = r = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lf%lf%lf", x + i, y + i, z + i);
			l = max(l, z[i]);
		}
		r = 0x3f3f3f3f;


		double ansh, ansr;
		ansh = ansr = 0;

		while (r - l >= eps) {
			double mid = (l + r) / 2.0;
			double mmid = (mid + r) / 2.0;
			double r1 = getR(mid);
			double r2 = getR(mmid);
			ansh = mid;
			ansr = r1;
			if (mid * r1 * r1 < mmid * r2 * r2) 
				r = mmid;
			else 
				l = mid;
		}
		printf("%.3f %.3f\n", ansh, ansr);
	}
	

	return 0;
}
