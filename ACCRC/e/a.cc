#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e4 + 10;
const double eps = 1e-8;

double x[N], y[N];
double d[N];
double a, b, c;
const double PI = acos(-1);

double getDis(int s, int e) {
	return sqrt((x[s] - x[e]) * (x[s] - x[e]) + (y[s] - y[e]) * (y[s] - y[e]));
}

double cal(double a, double b, double c, double x) {
	return PI * (a * x * x + b * x + c);
}

double getAns(double a, double b, double c, double l, double r) {
	if (l > r) {
		return -1;
	}

	double mid, mmid;	

	while (fabs(l - r) > eps) {

		mid = (l + r) / 2.0;
		mmid = (mid + r) / 2.0;
		if (cal(a, b, c, mid) <= cal(a, b, c, mmid)) {
			r = mmid;
		}
		else 
			l = mid;
	}

	return l;

}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {

		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) 
			scanf("%lf%lf", x + i, y + i);

		for (int i = 2; i <= n; i++) {
			d[i - 1] = getDis(i, i - 1);
		}
		d[n] = getDis(n, 1);

		double l = 0, r = min(d[1], d[n]);

		b = c = 0;
		a = 1;
		double tmp = 0;
		int flag = -1;
		for (int i = 1; i < n; i++) {
			tmp = d[i] - tmp;
			if (flag == -1) {
				r = min(tmp, r);
			}
			else {
				l = max(-tmp, l);
			}
			a += 1;
			b += flag * tmp * 2;
			c += tmp * tmp;
			flag *= -1;
		}
		if (l > r) {
			printf("IMPOSSIBLE\n");
			continue;
		}

		double x;
		if (n % 2 == 1) {
			x = (d[n] - tmp) / 2.0;
			if (x >= 0) {
				printf("%.2lf\n", cal(a, b, c, x));
				printf("%.2lf\n", x);
				tmp = x;
				for (int i = 1; i < n; i++) {
					tmp = d[i] - tmp;
					printf("%.2lf\n", tmp);
				}

			}
			else 
				printf("IMPOSSIBLE\n");
		}
		else {
			if ((fabs(tmp - d[n]) < eps)) {
				x = getAns(a, b, c, l, r);
				if (x < 0) {
					printf("IMPOSSIBLE\n");
				}
				else {
					printf("%.2lf\n", cal(a, b, c, x));
					printf("%.2lf\n", x);
					tmp = x;
					for (int i = 1; i < n; i++) {
						tmp = d[i] - tmp;
						printf("%.2lf\n", tmp);
					}
				}
			}
			else {
				printf("IMPOSSIBLE\n");
			}
		}
	}


	return 0;
}
