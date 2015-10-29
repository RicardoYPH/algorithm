#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int N = 510;

int num[N * N];
int ans[N];
map <int, int> M;

int gcd(int a, int b) {
	return b == 0 ? a : gcd (b, a % b);
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n * n; i++) {
		scanf("%d", num + i);	
		M[num[i]]++;		
	}

	sort (num + 1, num + 1 + n * n);

	int cnt = 0;
	for (int i = n * n; i >= 1; i--) {
		if (M[num[i]] == 0)
			continue;
		ans[cnt++] = num[i];
		M[num[i]]--;
		for (int j = 0; j < cnt - 1; j++) {
			int tmp = gcd(ans[j], num[i]);	
			M[tmp] = M[tmp] - 2;
		}
	}


	printf("%d", ans[0]);
	for (int i = 1; i < cnt; i++) 
		printf(" %d", ans[i]);
	printf("\n");
	return 0;
}
