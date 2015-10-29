#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int eps = 1e-8;

int main() {
	double num[1010];
	memset(num, 0, sizeof(num));
	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		int ind;
		double tmp;
		scanf("%d%lf", &ind, &tmp);
		num[ind] += tmp;
	}

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int ind;
		double tmp;
		scanf("%d%lf", &ind, &tmp);
		num[ind] += tmp;
	}

	int total = 0;
	for (int i = 0; i < 1010; i++) {
		if (num[i] != 0) {
			total++;	
		}	
	}
	printf("%d", total);

	for (int i = 1009; i >= 0; i--) {
		if (num[i] != 0) {
			printf(" %d %.1lf", i, num[i]);
		}	
	}
	printf("\n");

	return 0;

}
