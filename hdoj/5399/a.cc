#include <cstdio>
#include <cstring>

typedef long long ll;

const int N = 110;
const ll MOD = 1e9 + 7;

ll num[N][N];
int cnt;
int n, m;

bool judge () {
	int tmp[N];
	for (int i = 0; i < N; i++) 
		tmp[i] = i;
	for (int i = cnt - 1; i >= 0; i--)  {
		for (int j = 1; j <= n; j++) {
			tmp[j] = num[i][tmp[j]];
		}	
	}

	for (int i = 1; i <= n; i++)
		if (tmp[i] != i)
			return false;

	return true;

}

int main() {
	ll A[N];
	A[0] = 1;
	for (ll i = 1; i < N; i++)
		A[i] = (A[i - 1] * i) % MOD;


	bool vis[N];
	while (~scanf("%d%d", &n, &m)) {
		int tmp;
		int total = 0;
		bool flag = true;
		cnt = 0;
		memset(num, 0, sizeof(num));

		for (int i = 0; i < m; i++) {
			scanf("%lld", &tmp);	
			if (tmp == -1){
				total ++;	
			}
			else {
				memset(vis, 0, sizeof(vis));
				num[cnt][1] = tmp;
				for (int j = 2; j <= n; j++) {
					scanf("%lld", num[cnt] + j);	
				}

				for (int j = 1; j <= n; j++) {
					vis[num[cnt][j]] = true;	
				}

				for (int j = 1; j <= n; j++) {
					if (vis[j] == false) 
						flag = false;
				}
				cnt ++;
			}
		}
		if (flag == false){
			puts("0");	
			continue;
		}

		if (total == 0) {
			if (judge() == true) {
				printf("1\n");	
			}
			else {
				printf("0\n");
			}
			continue;
		}

		ll ans = 1;
		for (int i = 0; i < total - 1; i++) {
			ans = (ans * A[n]) % MOD;	
		}
		printf("%lld\n", ans);
	
	}

	return 0;
}

