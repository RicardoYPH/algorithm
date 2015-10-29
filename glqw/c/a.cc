#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

double ans[N];

int main() {
	memset(ans, 0, sizeof(ans));
	ans[1] = 0;
	for (int i = 2; i < N; i++) {
		ans[i] = 0;
		int cnt = 0;
		int e = sqrt(i);
		if (i % e == 0 && e != 1) {
			if (i / e == e) {
				cnt += 1;	
				ans[i] += ans[e];
			}
			else  {
				cnt += 2;
				ans[i] = ans[i] + ans[e] + ans[i / e]; 
			}
		}

		for (int j = 2; j < e; j++) {
			if (i % j == 0) {
				cnt += 2;	
				ans[i] = ans[j] + ans[i] + ans[i / j];
			}
		}
		ans[i] = (ans[i] + (double) cnt + 2.0) / (double) (cnt + 1.0);
	}



	int t;
	scanf("%d", &t);
	int CASE = 1;

	while (t--) {
		int n;
		scanf("%d", &n);
		printf("Case %d: %.20lf\n", CASE++, ans[n]);
	
	}


	return 0;
}
