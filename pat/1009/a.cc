#include <bits/stdc++.h>

using namespace std;

const int N = 40;

int e[N];
double c[N];
double ans[3000];

int main() {

	int k1, k2;
	
	vector <pair<int, double> > V;

	memset(c, 0, sizeof(c));
	memset(e, 0, sizeof(e));
	memset(ans, 0, sizeof(ans));

	scanf("%d", &k1);
	for (int i = 1; i <= k1; i++) {
		scanf("%d%lf", e + i, c + i);
	}
	scanf("%d", &k2);

	int te;
	double tc;
	for (int i = 1; i <= k2; i++) {
		scanf("%d%lf", &te, &tc);
		for (int j = 1; j <= k1; j++) {
			ans[te + e[j]] += tc * c[j];
		}
	}
	for (int i = 2001; i >= 0; i--) {
		if (fabs(ans[i] - 0.0) > 1e-8) {
			V.push_back(make_pair(i, ans[i]));
		}
	}

	int e = V.size();
	printf("%d", e);

	for (int i = 0; i < e; i++) {
		printf(" %d %.1f", V[i].first, V[i].second);
	}


	return 0;
}
