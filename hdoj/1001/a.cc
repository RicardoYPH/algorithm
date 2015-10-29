#include <cstdio>
#include <cstring>

using namespace std;

int main() {

	double n;

	while (~scanf("%lf", &n)) {
	
		double ans = (n * (n + 1)) / 2;
		printf("%.0lf\n\n", ans);
	
	}

	return 0;
}
