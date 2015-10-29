#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 4010;

typedef long long ll;

ll v[N], d[N], p[N];
int flag[N];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1;i <= n ;i++) {
		scanf("%lld%lld%lld", v + i, d + i, p + i);	
	}


	ll ca, cb;
	ca = cb = 0;
	int ans[N];
	int cnt = 0;
	memset(flag, 0, sizeof (flag));
	for (int i = 1; i <= n; i++) {
		if (flag[i] == 1) continue;
		ans[cnt++] = i;
		ca = v[i];	
		cb = 0;
		for (int j = i + 1; j <= n; j++) {
			if (flag[j] == 1) continue;
			p[j] -= ca;
			if (ca > 0) ca --;
		}
		for (int j = i + 1; j <= n; j++) {
			if (flag[j] == 1) continue;
			p[j] -= cb;			
			if (p[j] < 0) {
				cb += d[j];
				flag[j] = 1;
			}
		}
	}
	printf("%d\n", cnt);

	for (int i = 0; i < cnt - 1; i++) {
		printf("%d ", ans[i]);	
	}
	printf("%d\n", ans[cnt - 1]);
	
	return 0;
}
