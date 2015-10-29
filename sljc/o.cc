#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 4000000 + 10;

int phi[MAXN];
ll ans[MAXN];

void get_phi() {
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < MAXN; i++) 
		phi[i] = i;

	for (int i = 2; i < MAXN; i += 2)
		phi[i] /= 2;

	for (int i = 3; i < MAXN; i += 2) if (phi[i] == i)
		for (int j = i; j < MAXN; j += i) 
			phi[j] = phi[j] / i * (i - 1);

	for (int i = 2; i < MAXN; i++) 
		for (int j = 1; i * j < MAXN; j ++) 
			ans[j * i] += j * phi[i];

	for (int i = 1; i < MAXN; i++)
		ans[i] += ans[i - 1];
}

int main() {

	get_phi();
	int n;
	while (~scanf("%d", &n) && n) 
		printf("%lld\n", ans[n]);
	return 0;
}
