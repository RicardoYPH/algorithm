#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 510;
const double pi = acos(-1);
const double eps = 1e-8;

double x[N], y[N];
int n;

double calc(double a) {
	double Maxx, Maxy, Minx, Miny;
	Minx = Miny = 0x3f3f3f3f;
	Maxx = Maxy = -0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		double tx = x[i] * cos(a) - y[i] * sin(a);
		double ty = x[i] * sin(a) + y[i] * cos(a);
		Minx = min(tx, Minx);
		Maxx = max(tx, Maxx);
		Miny = min(ty, Miny);
		Maxy = max(ty, Maxy);
	}
	return max(Maxx - Minx, Maxy - Miny);
}

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lf%lf", x + i, y + i);
		}
		double l = 0, r = pi;

		double ans = 0;
		while (r - l > eps) {
			double mid = (r + l) / 2.0;
			double mmid = (r + mid) / 2.0; 
			ans = calc(mid);
			if (ans <= calc(mmid)) 
				r = mmid;
			else 
				l = mid;
		}
		printf("%.2f\n", ans * ans);
		
	}

	return 0;
}
