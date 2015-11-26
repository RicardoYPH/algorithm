#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;

double x, y, l, d;

double getY(double a) {
	return -(x - l * sin(a) - d / cos(a)) / tan(a);	
}

int main() {

	while (~scanf("%lf%lf%lf%lf", &x, &y, &l, &d)) {
		double L, R;
		L = 0; R = pi / 2.0;	
		double ans = 0;
		if (x < d || y < d) {
			puts("no");
			continue;
		}
		double tmp = 0;
		while (R - L > eps) {
			double mid = (L + R) / 2.0;
			double mmid = (mid + R) / 2.0;
			double t1 = getY(mid);
			double t2 = getY(mmid);
			tmp = t1;
			if (t1 > t2) 
				R = mmid;
			else 
				L = mid;
		}
		if (tmp > y) 
			printf("no\n");
		else 
			printf("yes\n");

	}

	return 0;
}
