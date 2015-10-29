#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;
const int N = 5 * 1e4 + 10;
ll num[N];
double dpa[N], dpo[N], dpx[N];
int main() {

	int t;
	scanf("%d", &t);
	int CASE = 1;

	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) 
			scanf("%lld", num + i);

		double all = ((double)n * (n + 1)) / 2.0;

		double suma, sumo, sumx;
		double ansa, anso, ansx;
		memset(dpa, 0, sizeof(dpa));
		memset(dpo, 0, sizeof(dpo));
		memset(dpx, 0, sizeof(dpx));
		for (int i = 0; i < 31; i++) {
			suma = sumo = sumx = 0;
			for (int j = 1; j <= n; j++) {
				if (num[j] & (1LL << i)) {
					dpa[j] = dpa[j - 1] + 1;
					dpo[j] = j;
					dpx[j] = j - dpx[j - 1];
				}		
				else {
					dpa[j] = 0;
					dpo[j] = dpo[j - 1];	
					dpx[j] = dpx[j - 1];
				}
				suma += dpa[j];
				sumo += dpo[j];
				sumx += dpx[j];
			}	
			ansa += (1LL << i) * suma / all;
			anso += (1LL << i) * sumo / all;
			ansx += (1LL << i) * sumx / all;
		}
		printf("Case #%d: %.6lf %.6lf %.6lf\n", CASE++, ansa, anso , ansx);
		

	}


	return 0;
}
