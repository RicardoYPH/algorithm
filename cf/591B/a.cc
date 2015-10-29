#include <bits/stdc++.h>

using namespace std;

int main() {

	double n, p, q;

	scanf("%lf%lf%lf", &n, &p, &q);

	double t = n / (p + q);

	printf("%.5lf\n", p * t);


	return 0;
}
